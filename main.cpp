#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, int numNodes, vector<vector<pair<int,int>>>& graph) {
    vector<int> dist(numNodes, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i].first;
            int weight = graph[node][i].second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int numNodes = 6;
    vector<vector<pair<int,int>>> graph(numNodes);

    // build the graph from the image
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 9});
    graph[0].push_back({4, 2});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});
    graph[3].push_back({5, 1});
    graph[4].push_back({2, 3});
    graph[4].push_back({5, 8});

    // part 1: shortest path from node 0
    cout << "Shortest distances from node 0:" << endl;
    vector<int> dist0 = dijkstra(0, numNodes, graph);
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": ";
        if (dist0[i] == INF)
            cout << "unreachable" << endl;
        else
            cout << dist0[i] << endl;
    }

    cout << endl;

    // part 2: shortest path from node 1
    cout << "Shortest distances from node 1:" << endl;
    vector<int> dist1 = dijkstra(1, numNodes, graph);
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": ";
        if (dist1[i] == INF)
            cout << "unreachable" << endl;
        else
            cout << dist1[i] << endl;
    }

    return 0;
}
