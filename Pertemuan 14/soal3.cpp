#include <iostream>
#include <vector>

using namespace std;

class WeightedGraph {
private:
    int V;

    vector<vector<pair<int,int>>> adj;

public:
    WeightedGraph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void display() {
        cout << "Weighted Graph:\n";

        for(int i = 0; i < V; i++) {

            cout << i << " -> ";

            for(auto edge : adj[i]) {
                cout << "("
                     << edge.first
                     << ", w=" << edge.second
                     << ") ";
            }

            cout << endl;
        }
    }
};

int main() {

    WeightedGraph g(8);

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,3,5);
    g.addEdge(1,4,10);
    g.addEdge(2,5,3);
    g.addEdge(3,6,6);
    g.addEdge(4,7,1);

    g.display();

    return 0;
}