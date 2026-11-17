#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v[i] = a - (i + 1);
    }

    sort(v.begin(), v.end());

    ll res = 1;
    ll curr_streak = 1;

    for (ll i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            continue; 
        }
        
        if (v[i] == v[i - 1] + 1) {
            curr_streak++;
        } else {
            curr_streak = 1;
        }
        
        res = max(res, curr_streak);
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}