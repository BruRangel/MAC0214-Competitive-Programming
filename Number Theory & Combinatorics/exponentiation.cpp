#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll exp_binaria(ll a, ll b) {
    a %= MOD;
    ll res = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }

    return res;
}

void solve() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cout << exp_binaria(a, b) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}