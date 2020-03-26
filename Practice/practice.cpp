#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << ", " << e->w << ") ";
        }
        cout << endl;
    }
}

void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
        return;

    graph[u].push_back(new Edge(v, w));
    //graph[v].push_back(new Edge(u, w));
}

void hasPath(int src, int dest, vector<bool> &vis, string psf){
    cout<<psf<<endl;
    vis[src] = true;
    for(Edge *e: graph[src]){
        if(!vis[e->v]){
            hasPath(e->v, dest, vis, psf+to_string(e->v));
        }
    }

}

void allPath(int src, int dest, vector<bool> &vis, string psf){
    if(src == dest){
        cout<<psf<<endl;
    }
    vis[src] = true;
    for(Edge *e: graph[src]){
        if(!vis[e->v]){
            hasPath(e->v, dest, vis, psf+to_string(e->v));
        }
    }   
    vis[src] = false;
}

int allPathWeighted(int src, int dest, vector<bool> &vis, int wsf, string psf)
{
    if (src == dest)
    {
        cout << psf + " @ " + to_string(wsf) << endl;
        return 1;
    }
    int count = 0;
    // cout << psf << endl;
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            count += allPathWeighted(e->v, dest, vis, wsf + e->w, psf + to_string(e->v));
        }
    }
    vis[src] = false;
    return count;
}
void constructGraph(){
    // addEdge(0, 1, 10);
    // addEdge(0, 3, 10);
    // addEdge(1, 2, 10);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 2);
    // addEdge(4, 6, 3);
    // addEdge(5, 6, 8);
    // addEdge(1, 2, 8);
    // addEdge(2, 3, 8);

    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    //addEdge(4, 5, 2);
    addEdge(5, 6, 3);
    addEdge(6, 4, 8);
}

void removeEdge(int u, int v)
{
    int i = 0;
    while (i < graph[u].size())
    {
        Edge *e = graph[u][i];
        if (e->v == v)
        {
            break;
        }
        i++;
    }

    int j = 0;
    while (j < graph[v].size())
    {
        Edge *e = graph[v][j];
        if (e->v == u)
        {
            break;
        }
        j++;
    }

    graph[u].erase(graph[u].begin() + i);
    graph[v].erase(graph[v].begin() + j);
}

void removeVtx(int u)
{
    while (graph[u].size() != 0)
    {
        Edge *e = graph[u][graph[u].size() - 1];
        removeEdge(u, e->v);
    }
}

int swsf = 1e8;
string spsf = "";

int lwsf = -1;
string lpsf = "";

void allSolutionsMinMax(int src, int desti, vector<bool> &vis, int wsf, string psf)
{
    if (src == desti)
    {
        if (wsf < swsf)
        {
            swsf = wsf;
            spsf = psf;
        }

        if (wsf > lwsf)
        {
            lwsf = wsf;
            lpsf = psf;
        }
    }

    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            allSolutionsMinMax(e->v, desti, vis, wsf + e->w, psf + to_string(src) + "->");
    }
    vis[src] = false;
}

void dfs(int src, vector<bool> &vis)
{
    vis[src] = true;
    for (Edge *e : graph[src])
        if (!vis[e->v])
            dfs(e->v, vis);
}

void getConnectedComponents()
{
    vector<bool> vis(n, false);
    int compo = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            compo++;
            dfs(i, vis);
        }
    }
    cout << compo << endl;
}

void bfs(int src){
    vector<bool> vis(n,false);
    queue<int> que;
    que.push(src);
    que.push(-1);

    int cycle = 0; int level = 0;
    int dest = 6;

    bool isDest = false;
    while (que.size() != 1)
    {
        int rvtx = que.front();
        que.pop();
        if (rvtx == -1)
        {
            level++;
            que.push(-1);
            continue;
        }
        if (vis[rvtx])
        {
            cout << "cycle: " << ++cycle << " @ " << rvtx << endl;
            continue;
        }

        if (rvtx == dest && !isDest)
        {
            cout << "Destination: " << level << endl;
            isDest = true;
        }

        vis[rvtx] = true;
        for (Edge *e : graph[rvtx])
            if (!vis[e->v])
                que.push(e->v);
    }

}


void bfs2(int src)
{
    queue<int> que;
    vector<bool> vis(n, false);

    que.push(src);

    bool isDest = false;
    int cycle = 0, level = 0;
    int dest = 6;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            if (vis[rvtx])
            {
                cout << "cycle: " << ++cycle << " @ " << rvtx << endl;
                continue;
            }

            if (rvtx == dest && !isDest)
            {
                cout << "Destination: " << level << endl;
                isDest = true;
            }

            vis[rvtx] = true;
            for (Edge *e : graph[rvtx])
                if (!vis[e->v])
                    que.push(e->v);
        }
        level++;
    }
}

int hamiltonianPath(int vtx, int osrc, vector<bool> &vis, string ans, int vtxCount){
    if(vtxCount == (n-1)){
        bool flag = false;
        for(Edge *e: graph[vtxCount]){
            if(e->v == osrc){
                cout<<"Cycle"<<endl;
                flag = true;
            }
        }
        if(!flag){
            cout<<"Path: "<<ans+ to_string(vtx)<<endl;
            return 1;
        }
    }
    vis[vtx] = true;
    int count = 0;
    for (Edge *e : graph[vtx])
        if (!vis[e->v])
            count += hamiltonianPath(e->v, osrc,vis, ans + to_string(vtx) + " ", vtxCount + 1);
    vis[vtx] = false;
    return count;
}
bool isBipartite_(int i, vector<int> &vis){
    queue<pair<int, int>> que;
    bool flag = true;
    que.push({i, 0});

    while (que.size() != 0)
    {
        pair<int, int> rvtx = que.front();
        que.pop();

        if (vis[rvtx.first] != -1)
        {
            if (vis[rvtx.first] != rvtx.second)
            {
                cout << "conflict: " << endl;
                flag = false;
            }
            continue;
        }

        vis[rvtx.first] = rvtx.second;
        for (Edge *e : graph[rvtx.first])
        {
            if (vis[e->v] == -1)
                que.push({e->v, (rvtx.second + 1) % 2});
        }
    }

    return flag;
}


void isBipartite(){
    vector<int> vis(graph.size(), -1);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == -1){
            cout << count << " " << (boolalpha) << isBipartite_(i, vis) << endl;
            count++;
        }
    }
}


bool topologicalSort(int src, vector<bool> &vis, vector<bool> &check, vector<int> &stack)
{
    vis[src] = true;
    check[src] = true;
    bool res = false;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            res = res || topologicalSort(e->v, vis, check, stack);
        }
        else if (check[e->v])
        {
            return true;
        }
    }
    stack.push_back(src);
    check[src] = false;
    return res;
}

vector<int> topologicalSort()
{
    vector<bool> vis(graph.size(), false);
    vector<bool> check(graph.size(), false);
    vector<int> stack;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            topologicalSort(i, vis, check, stack);
    }
    // if ((stack.size() < n))
    // {
    //     cout << "NO TOPOLOGICAL SORT POSSIBLE";
    // }
    // else
    // {
    //     while (stack.size() != 0)
    //     {
    //         cout << stack.back() << " ";
    //         stack.pop_back();
    //     }
    // }
    return stack;
}

void kahnAlgo(){
    vector<int> stack(n,0);
    for(int i = 0; i < graph.size(); i++){
        for(Edge *e : graph[i]){
            stack[e->v]++;
        }
    }
    queue<int> que;
    for(int i = 0; i < stack.size(); i++){
        if(stack[i] == 0){
            que.push(i);
        }
    }
    vector<int> ans;
    while(que.size() != 0){
        int rvtx = que.front();
        que.pop();
        ans.push_back(rvtx);
        for(Edge *e : graph[rvtx]){
            stack[e->v]--;
            if(stack[e->v] == 0){
                que.push(e->v);
            }
        }
    }
    if(ans.size() != n) {
        cout<<"CYCLE";
    }   
    else{
        for(int i = 0; i < ans.size(); i++){
            cout<< ans[i]<<" ";
        }
    }
}
vector<vector<Edge*>> inv_graph(n, vector<Edge*>());

void inverse_graph(){
    for(int i = 0; i < n; i++){
        for(Edge* e : graph[i]){
            inv_graph[e->v].push_back(new Edge(i, e->w));
        }
    }
}

void kosarajuAlgo(){
    vector<int> stack = topologicalSort();
    inverse_graph();
    int comp = 0;
    int n = stack.size() - 1;

    while(n >= 0){
        cout<<stack[n]<<" ";
        n--;
    }
    cout<<endl;
    vector<bool> visited(n,false);
    while(stack.size() != 0){
        int rvtx = stack.back();
        stack.pop_back();

        if(!visited[rvtx]){
            comp++;
            dfs(rvtx, visited);
            cout<<endl;
        }
    }
    cout<<"Strongly Connected Component: "<<comp;
}

void solutions(){
    vector<bool> vis(n,false);
    constructGraph();
    // hasPath(0,6, vis, "0 ");
    // allPath(0,6, vis, "0 ");
    // allPathWeighted(0,6,vis, 0,"0 ");
    // allSolutionsMinMax(0,6,vis, 0,"");
    // cout<< lpsf << endl;
    // cout<< spsf;
    display();
    // bfs2(0);
    //bfs(0);
    //hamiltonianPath(0,0,vis, "", 0);
    cout<<endl;
    //isBipartite();
    //topologicalSort();
    //kahnAlgo();
    kosarajuAlgo();
}
int main(){
    solutions();
    return 0;
}