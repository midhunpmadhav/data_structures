/*
 * Author      : Midhun P
 * Description : Breadth first search traversal
 * Remarks     : BFS by recursion
 */

#include<iostream>
#include<list>

using namespace std;

class Graph {
    private :
        int v;
        bool* visited;
        list<int>* adj;  

    public :
        Graph(int n) {
            v = n;
            visited = new bool[v];
            adj = new list<int>[v];
        }

        void add_edge(int x, int y) {
            adj[x].push_back(y);
        }

        void rem_edge(int x, int y) {
            adj[x].remove(y);
        }

        void clear_visited() {
            for(int i = 0; i < v; ++i) {
                visited[i] = false;
            }
        }

        void dfs_r(int start) {
            cout << start << " ";
            visited[start] = true;

            for(list<int>::iterator i = adj[start].begin(); i != adj[start].end(); ++i) {
                if(!visited[*i]) {
                    dfs_r(*i);
                }
            }
        }

        void dfs_recursion(int start) {
            clear_visited();
            dfs_r(start);
            cout << endl;
        }
};

int main() {
    Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 

    cout << "DFS (recursion): "; 
    g.dfs_recursion(2);
}