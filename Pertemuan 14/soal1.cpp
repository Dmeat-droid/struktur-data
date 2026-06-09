#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void display() {
        cout << "Adjacency List:\n";

        for (int i = 0; i < V; i++) {
            cout << i << " -> ";

            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    Graph g(8);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    g.addEdge(4,7);

    g.display();

    return 0;
}