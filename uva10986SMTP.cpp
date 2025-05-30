#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int tc = 1; tc <= N; ++tc) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<long long> dist(n, INF);
        dist[S] = 0;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        pq.push(make_pair(0LL, S));

        while (!pq.empty()) {
            pair<long long,int> top = pq.top(); pq.pop();
            long long d = top.first;
            int u = top.second;
            if (d > dist[u]) continue;
            for (int i = 0; i < (int)adj[u].size(); ++i) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push(make_pair(nd, v));
                }
            }
        }

        cout << "Case #" << tc << ": ";
        if (dist[T] == INF) {
            cout << "unreachable\n";
        } else {
            cout << dist[T] << "\n";
        }
    }

    return 0;
}
