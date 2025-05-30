#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to;
    int weight;
};

const int MAXN = 1e5 + 5;
vector<Edge> adj[MAXN];

void k_shortest_paths(int n, int k) {
    // Min-heap for traversal: (cost, node)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    // Stores up to k smallest distances to node n
    vector<vector<long long>> dist(n + 1);

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u].size() >= k) continue;
        dist[u].push_back(cost);

        for (Edge e : adj[u]) {
            int v = e.to;
            long long w = e.weight;
            pq.push({cost + w, v});
        }
    }

    for (long long price : dist[n]) {
        cout << price << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    k_shortest_paths(n, k);
    return 0;
}
