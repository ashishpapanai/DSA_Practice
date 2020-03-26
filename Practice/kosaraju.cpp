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
vector<vector<Edge*>> inv_graph(n, vector<Edge*>());
void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
        return;

    graph[u].push_back(new Edge(v, w));
    //graph[v].push_back(new Edge(u, w));
}
void constructGraph(){
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(5, 6, 3);
    addEdge(6, 4, 8);
}

void dfs(int src, vector<bool> &vis)
{
    vis[src] = true;
    for (Edge *e : inv_graph[src])
        if (!vis[e->v])
            dfs(e->v, vis);
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
    return stack;
}


void inverse_graph(){
    for(int i = 0; i < n; i++){
        for(Edge* e : graph[i]){
            inv_graph[e->v].push_back(new Edge(i, e->w));
        }
    }
}

void kosarajuAlgo(){
    vector<int> stack = topologicalSort();
    // for(int i = 0; i < stack.size(); i++){
    //     cout<<stack[i]<<endl;
    // }
    inverse_graph();
    int comp = 0;
    int n = stack.size() - 1;
    vector<bool> visited(n,false);
    while(stack.size() != 0){
        int rvtx = stack.back();
        stack.pop_back();

        if(!visited[rvtx]){
            comp++;
            dfs(rvtx, visited);
        }
    }
    cout<<"Strongly Connected Component: "<<comp;
}

void solutions(){
    kosarajuAlgo();
}
int main(){
    solutions();
    return 0;
}