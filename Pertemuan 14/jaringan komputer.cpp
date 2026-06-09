#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

class NetworkGraph {
private:
    int vertices;

    vector<string> deviceNames;

    vector<vector<pair<int,int>>> adjList;

public:
    NetworkGraph(int v) {
        vertices = v;
        adjList.resize(v);
        deviceNames.resize(v);
    }

    void setDevice(int id, string name) {
        deviceNames[id] = name;
    }

    void connectDevices(int a, int b, int latency) {
        adjList[a].push_back({b, latency});
        adjList[b].push_back({a, latency});
    }

    void showNetwork() {
        cout << "\n=== TOPOLOGI JARINGAN ===\n";

        for(int i = 0; i < vertices; i++) {

            cout << deviceNames[i] << " -> ";

            for(auto edge : adjList[i]) {
                cout << "("
                     << deviceNames[edge.first]
                     << ", "
                     << edge.second
                     << " ms) ";
            }

            cout << endl;
        }
    }

    void shortestLatency(int source) {

        vector<int> distance(vertices, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        distance[source] = 0;
        pq.push({0, source});

        while(!pq.empty()) {

            int current = pq.top().second;
            pq.pop();

            for(auto edge : adjList[current]) {

                int neighbor = edge.first;
                int latency = edge.second;

                if(distance[current] + latency
                   < distance[neighbor]) {

                    distance[neighbor] =
                        distance[current] + latency;

                    pq.push({
                        distance[neighbor],
                        neighbor
                    });
                }
            }
        }

        cout << "\n=== LATENCY DARI "
             << deviceNames[source]
             << " ===\n";

        for(int i = 0; i < vertices; i++) {

            cout << deviceNames[source]
                 << " -> "
                 << deviceNames[i]
                 << " = "
                 << distance[i]
                 << " ms"
                 << endl;
        }
    }
};

int main() {

    NetworkGraph network(5);

    network.setDevice(0, "PC-A");
    network.setDevice(1, "Switch");
    network.setDevice(2, "PC-B");
    network.setDevice(3, "Router");
    network.setDevice(4, "Server");

    network.connectDevices(0, 1, 1);
    network.connectDevices(1, 2, 2);
    network.connectDevices(1, 3, 4);
    network.connectDevices(3, 4, 3);

    network.showNetwork();

    network.shortestLatency(0);

    return 0;
}