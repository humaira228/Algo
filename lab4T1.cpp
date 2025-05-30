#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAXN = 5000 + 5;

struct Edge {
    int to;
    int weight;
};

int N, R;
vector<Edge> adj[MAXN];

// For k-th shortest path tracking: max-heap per node storing up to k best distances
vector< priority_queue<int> > distK;

void solve_case(int tc) {
    // Reset adjacency and distK for this test
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
        while (!distK[i].empty()) distK[i].pop();
    }

    // Read roads
    for (int i = 0; i < R; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge{v, w});
        adj[v].push_back(Edge{u, w});
    }

    int k = 2;        // second-shortest
    int src = 1;
    int dest = N;

    // Min-heap to explore paths: (currentCost, node)
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push(make_pair(0, src));
    distK[src].push(0);

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;

        // Explore neighbors
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i].to;
            int w = adj[u][i].weight;
            int newCost = d + w;

            if (distK[v].size() < k) {
                // Haven't found k paths yet
                distK[v].push(newCost);
                pq.push(make_pair(newCost, v));
            }
            else if (distK[v].top() > newCost) {
                // Found a better candidate among the k-th
                distK[v].pop();
                distK[v].push(newCost);
                pq.push(make_pair(newCost, v));
            }
        }
    }

    // Output the second-shortest distance to dest
    if (distK[dest].size() < k) {
        cout << "Case " << tc << ": -1\n";
    } else {
        cout << "Case " << tc << ": " << distK[dest].top() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    // Initialize distK with size based on max N
    distK.assign(MAXN, priority_queue<int>());

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> R;
        solve_case(tc);
    }
    return 0;
}
