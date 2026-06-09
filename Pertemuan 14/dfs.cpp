#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int vertices;

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
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

    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);

        cout << "\nHasil DFS: ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);

    graph.display();

    graph.DFS(0);

    return 0;
}