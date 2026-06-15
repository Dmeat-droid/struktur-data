#include <bits/stdc++.h>

#define INF 2e9

using namespace std;


class DijkstraGraph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList;
    vector<string> loc = {
        "Restoran",
        "A",
        "B",
        "C",
        "D",
        "E",
        "Pelanggan"
    };
public:
    DijkstraGraph(int vertices){
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int from, int to, int weight){
        adjList[from].push_back({to, weight});
    }

    void findShortestPath(int source, int destination){
        // vector menyimpan jarak terpendek
        vector<int> dist(numVertices, INF);

        // vector menyimpan node asal sebelum mencapai node index
        vector<int> parent(numVertices, -1);

        // menyimpan pair(jarak saat ini, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

        dist[source] = 0;
        pq.push({0, source});

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // kalo ada jarak queue lebih besar, maka diambild
            if(d > dist[u]) continue;

            // cek tetangga
            for(const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist[destination] == INF){
            cout << "tidak ada jalur dari " << source << " ke " << destination << '\n';
            return;
        }

        vector<int> path;
        for(int at = destination; at != -1; at = parent[at]) {
            path.push_back(at);
        }

        reverse(path.begin(), path.end());

        cout << "Jalur terpendek dari " << loc[source] << " ke "<< loc[destination] << ": ";
        for(size_t i = 0; i < path.size(); i++) {
            cout << loc[path[i]];
            if(i < path.size() -1) cout << " -> ";
        }
        cout << "\n Total waktu yang diperlukan: " << dist[destination] << '\n';
    }

    void printResult(int source, const vector<int> dist) {
        cout << "Jarak terpendek dari vertex " << source << ":\n";
        for(int i = 0; i < numVertices; i++) {
            cout << "Ke vertex " << i << "->";
            if(dist[i] == INF) cout << "Unreachable\n";
            else cout << dist[i] << "\n";
        }
    }

};

int main(){
    DijkstraGraph g(7);

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(0,3,7);
    g.addEdge(1,2,3);
    g.addEdge(1,5,6);
    g.addEdge(2,3,3);
    g.addEdge(2,4,2);
    g.addEdge(2,5,3);
    g.addEdge(3,4,4);
    g.addEdge(4,6,3);
    g.addEdge(5,6,4);

    g.findShortestPath(0, 6);

    return 0;
}