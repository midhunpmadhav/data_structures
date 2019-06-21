/*
 * Author      : Midhun P
 * Description : Breadth first search traversal
 * Remarks     : BFS using queue data structure
 */

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
private:
    int v;
    bool *visited;
    list<int> *adj;

public:
    Graph(int n)
    {
        v = n;
        visited = new bool[v];
        adj = new list<int>[v];
    }

    void add_edge(int x, int y)
    {
        adj[x].push_back(y);
    }

    void rem_edge(int x, int y)
    {
        adj[x].remove(y);
    }

    void clear_visited()
    {
        for (int i = 0; i < v; ++i)
        {
            visited[i] = false;
        }
    }

    void bfs(int start)
    {
        queue<int> q;

        clear_visited();
        q.push(start);

        while (!q.empty())
        {
            start = q.front();
            q.pop();

            visited[start] = true;
            cout << start << " ";
            for (auto i = adj[start].begin(); i != adj[start].end(); ++i)
            {
                if (!visited[*i])
                {
                    q.push(*i);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "BFS: ";
    g.bfs(2);
}