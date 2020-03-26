#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
vector<vector<Edge *>> graph(7, vector<Edge *>());
void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}
int n = 7;
void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " => ";
        for (Edge *e : graph[i])
        {
            cout << "( " << e->v << ", " << e->w << "), ";
        }
        cout << endl;
    }
}
void removeEdge(int u, int v)
{
    int i = -1;
    int j = -1;

    for (int k = 0; k < graph[u].size(); k++)
    {
        if (graph[u][k]->v == v)
        {
            i = k;
            break;
        }
    }

    for (int k = 0; k < graph[v].size(); k++)
    {
        if (graph[v][k]->v == u)
        {
            j = k;
            break;
        }
    }

    graph[u].erase(graph[u].begin() + i);
    graph[v].erase(graph[v].begin() + j);
}

void removeVtx(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        removeEdge(graph[u][i]->v, u);
    }

    // graph.erase(graph.begin()+u);
}
bool hasPath(int src, int dest, vector<bool> &visited, string psf)
{
    cout << psf << endl;
    visited[src] = true;
    for (Edge *e : graph[src])
    {
        if (!visited[e->v])
        {
            hasPath(e->v, dest, visited, psf + to_string(e->v));
        }
    }
    return false;
}
int allPath(int src, int dest, vector<bool> &visited, string psf)
{
    if (src == dest)
    {
        cout << psf << endl;
        return 1;
    }
    int count = 0;
    visited[src] = true;
    for (Edge *e : graph[src])
    {
        if (!visited[e->v])
        {
            count += allPath(e->v, dest, visited, psf + to_string(e->v));
        }
    }
    visited[src] = false;
    return count;
}
void allPathWeight(int src, int dest, vector<bool> &visited, int weight, string psf)
{
    if (src == dest)
    {
        cout << psf + " @" + to_string(weight) << endl;
    }
    visited[src] = true;
    for (Edge *e : graph[src])
    {
        if (!visited[e->v])
        {
            allPathWeight(e->v, dest, visited, weight + e->w, psf + to_string(e->v));
        }
    }
    visited[src] = false;
}
vector<int> weigh;
vector<string> path;
void allPathWeight2(int src, int dest, vector<bool> &visited, int weight, string psf)
{
    if (src == dest)
    {
        path.push_back(psf);
        weigh.push_back(weight);
    }
    visited[src] = true;
    for (Edge *e : graph[src])
    {
        if (!visited[e->v])
        {
            allPathWeight2(e->v, dest, visited, weight + e->w, psf + to_string(e->v));
        }
    }
    visited[src] = false;
}
void bfs(int src){
    queue<int> que;
    vector<bool> vis(n,false);
    que.push(src);
    que.push(-1);
   
    int cycle = 0, level = 0; int dest =6;
    while(que.size() != 1){
        int rvtx = que.front();
        que.pop();        
        if(vis[rvtx]){
            cout<< "Cycle: "<< ++cycle<< " @ "<< rvtx<<endl;
            continue;
        }
         if(rvtx == dest){
            cout<< "Goal @ "<< level<<endl;
        }
        vis[rvtx] = true;
        for(Edge* e: graph[rvtx]){
            if(!vis[e->v]){
                que.push(e->v);
            }
        }
        if(que.front() == -1){
            level++;
            que.pop();
            que.push(-1);
        }
       
    }    
}
void bfs2(int src){
    queue<int> que;
    vector<bool> vis(n, false);
    que.push(src);
    bool isDest = false;
    int cycle = 0, level = 0;
    int dest = 9;

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

            if (rvtx == dest&& !isDest)
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
int hamiltonian(int src,int osrc ,int vtxCount, vector<bool> &visited, string psf)
{
    bool flag = false;
    if (vtxCount == graph.size()-1)
    {
        for(Edge *e : graph[src]){
        if(e->v == osrc){    
        cout <<"Cycle : "+psf<< endl;
        flag = true;
        }
        }
        if(!flag){
            cout <<"Path: "+psf << endl;
        }
        return 1;
    }
    int count = 0;
    visited[src] = true;
    for (Edge *e : graph[src])
    {
        if (!visited[e->v])
        {
            count += hamiltonian(e->v,osrc ,vtxCount+1, visited, psf +to_string(e->v)+" ");
        }
    }
    visited[src] = false;
    return count;
}
bool biparted(int src){
    queue<pair<int, int>> que;
    vector<int> check(n,-1);
    pair<int, int> a;
    a.first = src;
    a.second = 0;
    que.push(a);
    vector<bool> vis(n, false);
    bool isDest = false;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = (que.front()).first;
            que.pop();
            int ch = (que.front()).second;
            int cnew = (ch+1)%2;
            if(check[rvtx] != -1 && check[rvtx] != cnew){
                return false;
            }
            vis[rvtx] = true;
            for (Edge *e : graph[rvtx])
                if (!vis[e->v]){
                    pair<int, int> b;
                    b.first = e->v;
                    b.second = (ch+1)%2;
                    que.push(b);
                    }
        }
    }
    return true;
}
bool isBipartite(int i, vector<int> &vis)
{
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
void isBipartite()
{
    vector<int> vis(graph.size(), -1);
    int count = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == -1&& !isBipartite(i, vis))
        {
            cout << count << " " << (boolalpha) << isBipartite(i, vis) << endl;
            count++;
        }
    }
}
void solve()
{
    for (int i = 0; i < 6; i++)
    {
        vector<Edge *> ar;
        graph.push_back(ar);
    }
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 3);
    addEdge(5, 6, 8);
    // addEdge(0, 1, 10);
    // addEdge(0, 6, 10);
    // addEdge(1, 2, 10);
    // addEdge(2, 3, 40);
    // addEdge(0, 3, 10);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 2);
    // addEdge(5, 6, 8);
    // addEdge(4, 6, 3);
    // addEdge(2, 5, 10);
//-----------------------
    // addEdge(0,8,0);
    // addEdge(1,8,0);
    // addEdge(2,8,0);
    // addEdge(3,8,0);
    // addEdge(4,8,0);
    // addEdge(5,8,0);
    // addEdge(6,8,0);
    // addEdge(7,8,0);
    // addEdge(0,1,0);
    // addEdge(1,2,0);
    // addEdge(2,3,0);
    // addEdge(3,4,0);
    // addEdge(4,5,0);
    // addEdge(5,6,0);
    // addEdge(6,7,0);
    // addEdge(7,0,0);

    //display();
    vector<bool> vis(n, false);
    isBipartite();
    //cout<< hasPath(0,6, vis, "0")<< endl;;
    //cout<< allPath(0,6,vis, "0")<< endl;
    // allPathWeight3(0, 6, vis, 0, "0");
    // cout << pathLarg + " @";
    // cout<<(msf)<< endl;
    // cout << pathSmall + " @";
    // cout<<(minsf);
    // cout<<endl;
    // allPathWeight2(0,6,vis,0, "0");
    // maxima();
    // minima();

    // removeVtx(3);
    // addEdge(2, 5, 13);
}

int main()
{
    solve();
    return 0;
}
