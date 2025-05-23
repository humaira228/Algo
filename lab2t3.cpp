#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<LL> s(n),e(n);
    for(int i=0; i<n; i++){
        cin>> s[i];
    }
    for(int i=0; i<n; i++){
        cin>> e[i];
    }
    
    vector<pair<LL,LL>>activity(n);
    for(int i=0; i<n; i++){
        activity[i]={e[i],s[i]};
    }

    sort(activity.begin(), activity.end());
    int c=0;

    LL lastEnd=-1;

    for(auto& p:activity){
        LL end= p.first;
        LL start= p.second;
        if(start>=lastEnd){
            c++;
            lastEnd=end;
        }
    }
    cout<<c;

    
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
