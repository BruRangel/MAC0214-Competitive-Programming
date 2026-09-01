#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    set<ll> s;

    for (ll i = 0; i < n; i++) {
        ll c; 
        cin >> c;
        s.insert(c);
    }

    ll res = s.size();

    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}
