#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void solve() {
    int n;
    cin >> n;

    vector<LL> s(n), e(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> e[i];

    vector<pair<LL, LL>> activities(n);
    for (int i = 0; i < n; i++) {
        activities[i] = {e[i], s[i]};  // sort by end time
    }

    sort(activities.begin(), activities.end());

    int count = 0;
    LL last_end = -1;

    for (const auto& [end, start] : activities) {
        if (start >= last_end) {
            count++;
            last_end = end;
        }
    }

    cout << count;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
