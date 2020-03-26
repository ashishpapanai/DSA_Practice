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
int msf = -1;
string pathLarg = "";
int minsf = 1e8;
string pathSmall = "";
void allPathWeight3(int src, int dest, vector<bool> &visited, int wsf, string psf)
{
    if (src == dest)
    {
        if (msf < wsf)
        {
            msf = wsf;
            pathLarg = psf;
            return;
        }
        if (minsf > wsf)
        {
            minsf = wsf;
            pathSmall = psf;
            return;
        }
        return;
    }
    visited[src] = true;
    for (Edge *e : graph[src])
    {
        if (!visited[e->v])
        {
            allPathWeight3(e->v, dest, visited, wsf + e->w, psf + to_string(e->v));
        }
    }
    visited[src] = false;
}
void maxima()
{
    int max = weigh[0];
    int idx = 0;
    for (int i = 0; i < weigh.size(); i++)
    {
        if (max < weigh[i])
        {
            max = weigh[i];
            idx = i;
        }
    }
    cout << path[idx] + " @" + to_string(max) << endl;
}
void minima()
{
    int min = weigh[0];
    int idx = 0;
    for (int i = 0; i < weigh.size(); i++)
    {
        if (min > weigh[i])
        {
            min = weigh[i];
            idx = i;
        }
    }
    cout << path[idx] + " @" + to_string(min) << endl;
}
void solve()
{
    for (int i = 0; i < 6; i++)
    {
        vector<Edge *> ar;
        graph.push_back(ar);
    }
    addEdge(0, 1, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(0, 3, 10);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(5, 6, 8);
    addEdge(4, 6, 3);
    //display();
    vector<bool> vis(n, false);
    //cout<< hasPath(0,6, vis, "0")<< endl;;
    //cout<< allPath(0,6,vis, "0")<< endl;
    allPathWeight3(0, 6, vis, 0, "0");
    cout << pathLarg + " @";
    cout<<(msf)<< endl;
    cout << pathSmall + " @";
    cout<<(minsf);
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
