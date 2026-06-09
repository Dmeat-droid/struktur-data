#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix;
    int vertices;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    // Menambahkan edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // untuk graf tidak berarah
    }

    // Menampilkan adjacency matrix
    void display() {
        cout << "\nAdjacency Matrix:\n\n";

        cout << "   ";
        for(int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;

        for(int i = 0; i < vertices; i++) {
            cout << i << "  ";

            for(int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
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

    for(int i = 0; i < e; i++) {
        int u, v;

        cout << "Masukkan Edge (u v): ";
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    graph.display();

    return 0;
}