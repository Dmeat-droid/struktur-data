#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;

    // {tujuan, bobot}
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // undirected graph
    }

    void display() {
        cout << "\nWeighted Graph:\n";

        for(int i = 0; i < vertices; i++) {

            cout << i << " -> ";

            for(auto edge : adjList[i]) {
                cout << "("
                     << edge.first
                     << ", weight="
                     << edge.second
                     << ") ";
            }

            cout << endl;
        }
    }
};

int main() {

    Graph graph(5);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 5);

    graph.display();

    return 0;
}