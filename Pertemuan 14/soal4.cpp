#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void dijkstra(int start) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(V, INT_MAX);

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {

            int currentDist = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();

            for(auto edge : adj[currentVertex]) {

                int neighbor = edge.first;
                int weight = edge.second;

                if(dist[currentVertex] + weight < dist[neighbor]) {

                    dist[neighbor] =
                        dist[currentVertex] + weight;

                    pq.push({
                        dist[neighbor],
                        neighbor
                    });
                }
            }
        }

        cout << "Shortest Distance from Vertex "
             << start << endl;

        for(int i=0;i<V;i++) {
            cout << start
                 << " -> "
                 << i
                 << " = "
                 << dist[i]
                 << endl;
        }
    }
};

int main() {

    Graph g(8);

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,3,5);
    g.addEdge(1,4,10);
    g.addEdge(2,5,3);
    g.addEdge(3,6,6);
    g.addEdge(4,7,1);
    g.addEdge(5,7,8);

    g.dijkstra(0);

    return 0;
}