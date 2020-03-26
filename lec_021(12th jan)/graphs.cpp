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
vector<vector<Edge *>> graph;
void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}
void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "( " << graph[i][j]->v << ", " << graph[i][j]->w << "), ";
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
    display();
    // removeVtx(3);
    // addEdge(2, 5, 13);
}

int main()
{
    solve();
    return 0;
}
