#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<vector<int>> adj(MAXN);
vector<bool> visited(MAXN, false);
vector<int> component_roots;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
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

    // Find connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            component_roots.push_back(i);
            dfs(i);
        }
    }

    // Output number of roads needed
    int roads_needed = component_roots.size() - 1;
    cout << roads_needed << endl;

    // Connect the components by linking their representatives
    for (int i = 0; i < roads_needed; i++) {
        cout << component_roots[i] << " " << component_roots[i + 1] << endl;
    }

    return 0;
}
 