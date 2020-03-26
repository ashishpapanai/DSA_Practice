#include <iostream>
#include <vector>
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

int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());
vector<vector<Edge *>> dGraph(n, vector<Edge *>());
vector<int> dShortestPath(n, 0);

void display(vector<vector<Edge *>> &gp)
{
    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << " -> ";
        for (Edge *e : gp[i])
        {
            cout << "(" << e->v << ", " << e->w << ") ";
        }
        cout << endl;
    }
}

void addEdge(vector<vector<Edge *>> &gp, int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= n || v >= n)
        return;

    gp[u].push_back(new Edge(v, w));
    gp[v].push_back(new Edge(u, w));
}

void constructGraph()
{
    addEdge(graph, 0, 1, 11);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 20);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);

    // addEdge(0, 6, 8);
    // addEdge(2, 5, 8);
    // addEdge(8, 9, 8);
    // addEdge(7, 9, 8);

    // display(graph);
    cout << endl;
}

//________________DSU____________________

void merge(int p1, int p2, vector<int> &par, vector<int> &size){
    if(size[p1] < size[p2]){
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else{
        par[p2] = p1;
        size[p1] = size[p2];
    }
}
int findPar(int vtx, vector<int> &par){
    if(par[vtx] == vtx) return vtx;
    par[vtx] = findPar(par[vtx], par);
    return par[vtx];
}
void dsu(){
    vector<int> parent;
    vector<int> size(7,1);
    for(int i = 0; i < 7; i++){
        parent.push_back(i);
    }
    int cycle = 0;
    vector<vector <int>> edge{{0,1},{0,3},{1,2},{2,3},{3,4},{4,5},{4,6},{5,6}};      
    for(vector<int>  ele :edge){
        int p1 = findPar(ele[0], parent);
        int p2 = findPar(ele[1], parent);
        if(p1 == p2){
            ++cycle;
            cout<<"CYCLE #"<<cycle<<endl;
            cout<< ele[0]<< "-"<< ele[1]<<endl;
            continue;
        }
        merge(p1,p2,parent, size);
    } 
}
void solve()
{
    constructGraph();
    dsu();
}

int main()
{
    solve();
    return 0;
}