/*
 * Author      : Midhun P
 * Description : Depth first search traversal
 * Remarks     : DFS using stack data structure
 */

#include <iostream>
#include <list>
#include <stack>

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

    void dfs(int start)
    {
        stack<int> s;

        clear_visited();
        s.push(start);

        while (!s.empty())
        {
            start = s.top();
            s.pop();

            visited[start] = true;
            cout << start << " ";
            for (auto i = adj[start].rbegin(); i != adj[start].rend(); ++i)
            {
                if (!visited[*i])
                {
                    s.push(*i);
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

    cout << "DFS: ";
    g.dfs(2);
}