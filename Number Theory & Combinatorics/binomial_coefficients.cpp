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

    vector<pair<ll, ll>> queries(n);
    ll max_a = 0;
    for (ll i = 0; i < n; i++) {
        cin >> queries[i].first >> queries[i].second;
        max_a = max(max_a, queries[i].first);
    }

    vector<ll> fat(max_a + 1);
    vector<ll> inv_fat(max_a + 1);

    fat[0] = 1;
    for (ll i = 1; i <= max_a; i++) {
        fat[i] = (fat[i - 1] * i) % MOD;
    }

    // Inverso modular pelo Pequeno Teorema de Fermat
    inv_fat[max_a] = exp_binaria(fat[max_a], MOD - 2);
    for (ll i = max_a - 1; i >= 0; i--) {
        inv_fat[i] = (inv_fat[i + 1] * (i + 1)) % MOD;
    }

    for (ll i = 0; i < n; i++) {
        ll a = queries[i].first;
        ll b = queries[i].second;

        ll res = (fat[a] * inv_fat[b]) % MOD;
        res = (res * inv_fat[a - b]) % MOD;
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
