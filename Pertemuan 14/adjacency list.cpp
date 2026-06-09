#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // graf tidak berarah
    }

    void display() {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";

            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    int v, e;

    cout << "Jumlah Vertex : ";
    cin >> v;

    Graph graph(v);

    cout << "Jumlah Edge : ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v;

        cout << "Masukkan Edge (u v): ";
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    graph.display();

    return 0;
}