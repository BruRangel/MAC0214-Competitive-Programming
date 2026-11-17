#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    ll a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    ll minimo = min({a1, a2, a3});
    ll res = n - minimo;
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool have_testcases = true;

    if (have_testcases) {
        ll t;
        cin >> t;
        while (t--) {
            solve();
        }
    }
    else {
        solve();
    }
    
    return 0;
}