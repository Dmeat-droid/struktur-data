#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<pair<int,int>>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void display() {
        cout << "\nWeighted Graph:\n";

        for(int i = 0; i < vertices; i++) {
            cout << i << " -> ";

            for(auto edge : adjList[i]) {
                cout << "("
                     << edge.first
                     << ", w="
                     << edge.second
                     << ") ";
            }

            cout << endl;
        }
    }

    void dijkstra(int source) {

        vector<int> distance(vertices, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        distance[source] = 0;

        pq.push({0, source});

        while(!pq.empty()) {

            int currentDistance = pq.top().first;
            int currentVertex = pq.top().second;

            pq.pop();

            for(auto edge : adjList[currentVertex]) {

                int neighbor = edge.first;
                int weight = edge.second;

                if(distance[currentVertex] + weight
                   < distance[neighbor]) {

                    distance[neighbor] =
                        distance[currentVertex] + weight;

                    pq.push({
                        distance[neighbor],
                        neighbor
                    });
                }
            }
        }

        cout << "\nJarak Terpendek dari Vertex "
             << source << ":\n";

        for(int i = 0; i < vertices; i++) {
            cout << source
                 << " -> "
                 << i
                 << " = "
                 << distance[i]
                 << endl;
        }
    }
};

int main() {

    Graph graph(5);

    graph.addEdge(0,1,4);
    graph.addEdge(0,2,2);
    graph.addEdge(1,2,1);
    graph.addEdge(1,3,5);
    graph.addEdge(2,3,8);
    graph.addEdge(2,4,10);
    graph.addEdge(3,4,2);

    graph.display();

    graph.dijkstra(0);

    return 0;
}