#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
bool visited[MAXN];
int money[MAXN];

void dfs(int u, int &cnt, long long &sum) {
    visited[u] = true;
    cnt++;
    sum += money[u];
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, cnt, sum);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, m;
        cin >> n >> m;

        // reset
        long long total = 0;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        // read money and accumulate global total
        for (int i = 1; i <= n; i++) {
            cin >> money[i];
            total += money[i];
        }

        // read edges
        for (int i = 0, u, v; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1) global divisibility check
        bool ok = true;
        if (total % n != 0) {
            ok = false;
        } 
        else {
            long long target = total / n;
            // 2) per-component check
            for (int i = 1; i <= n && ok; i++) {
                if (!visited[i]) {
                    int cnt = 0;
                    long long sum = 0;
                    dfs(i, cnt, sum);
                    if (sum != cnt * target) {
                        ok = false; 
                        break;
                    }
                }
            }
        }

        cout << "Case " << tc << ": " << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
 