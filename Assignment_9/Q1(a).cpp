#include <iostream>
#include <vector>
#include<list>
#include <queue>
using namespace std;


class Graph {
    int V;
  list<int> *l;

public:
   
Graph(int V) {
        this->V = V;
        l=new list<int>[V];
    }


    void addEdge(int u, int v) {
        l[u].push_back(v);   
        l[v].push_back(u);
        

    }

    void BFS(int s) {

        queue<int> Q;
        vector<bool>vis(V,false);

       Q.push(s);
       vis[s]=true;

        cout << "BFS Traversal: ";

        while (Q.size()>0) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }

        cout << endl;
    }
    
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    g.BFS(start);

    return 0;
}
