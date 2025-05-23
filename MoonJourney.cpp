#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<vector<int>> adj(MAXN);
vector<bool> visited(MAXN, false);


int dfs(int node) {
    visited[node] = true;
    int size=1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            size+=dfs(neighbor);
        }
    }
    return size;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the undirected graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> componentSize;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int size=dfs(i);
            componentSize.push_back(size);
        }
    }

    long long total=(long long)n * (n - 1) / 2;

    long long sameCt=0;

    for (int size : componentSize) {
        sameCt+= (long long)size * (size - 1) / 2;
    }
cout << total - sameCt << endl;
}