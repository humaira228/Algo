#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX;
const int MAXN = 100000 + 5;

int n;
vector<pair<int,int>> adj[MAXN];
int parentArr[MAXN];

vector<long long> dijkstra(int start) {
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;

    for (int i = 1; i <= n; ++i)
        parentArr[i] = -1;

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    pq.push(make_pair(0LL, start));

    while (!pq.empty()) {
        pair<long long,int> top = pq.top(); 
        pq.pop();
        long long d = top.first;
        int u = top.second;
        if (d > dist[u]) continue;

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i].first;
            long long w = adj[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parentArr[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        adj[i].clear();

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<long long> dist = dijkstra(1);

    if (dist[n] == INF) {
        cout << -1 << "\n";
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = parentArr[v])
            path.push_back(v);
        for (int i = (int)path.size() - 1; i >= 0; --i)
            cout << path[i] << " ";
        cout << "\n";
    }

    return 0;
}
