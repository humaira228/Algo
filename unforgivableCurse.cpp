void solve() {
    int n, k = 0;
    string s, t;
    cin >> n >> k >> s >> t;

    unordered_map<char, int> f;

    for (auto& c : s) f[c]--;
    for (auto& c : t) f[c]++;
    for (auto& [c, t] : f) {
        if (t != 0) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        // If i is too close to the start or end, such that swapping isn’t possible,
        // and characters don't match, then it's impossible.
        if (i - k < 0 && i + k >= n && s[i] != t[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
