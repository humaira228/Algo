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
long long distArr[MAXN];
int trainCount[MAXN];
bool isTrainShortest[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        distArr[i] = LLONG_MAX;
        trainCount[i] = 0;
        isTrainShortest[i] = false;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    distArr[1] = 0;
    pq.push({0, 1});

    for (int i = 0; i < k; ++i) {
        int s;
        long long y;
        cin >> s >> y;
        trainCount[s]++;
        if (y < distArr[s]) {
            distArr[s] = y;
            isTrainShortest[s] = true;
            pq.push({y, s});
        }
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > distArr[u]) continue;
        for (auto &e : adj[u]) {
            int v = e.to;
            long long w = e.weight;
            long long nd = d + w;
            if (nd < distArr[v]) {
                distArr[v] = nd;
                isTrainShortest[v] = false;
                pq.push({nd, v});
            } else if (nd == distArr[v]) {
                isTrainShortest[v] = false;
            }
        }
    }

    long long redundant = 0;
    for (int city = 1; city <= n; ++city) {
        if (trainCount[city] == 0) continue;
        if (isTrainShortest[city]) {
            redundant += trainCount[city] - 1;
        } else {
            redundant += trainCount[city];
        }
    }

    cout << redundant << '\n';
    return 0;
}
