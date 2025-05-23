#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (!cin || (n == 0 && m == 0)) break;

        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);

        // Read the precedence relations
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Kahn's algorithm: enqueue all nodes with indegree == 0
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (indegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> topo;
        topo.reserve(n);

        // Process
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            topo.push_back(u);

            for (int v : adj[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Output one valid topological order
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << topo[i];
        }
        cout << "\n";
    }

    return 0;
}
