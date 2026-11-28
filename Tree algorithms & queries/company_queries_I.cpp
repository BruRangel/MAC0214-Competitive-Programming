#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, q;
    cin >> n >> q;

    ll pot = 1;
    ll log_n = 1;
    while (pot <= n) {
        pot *= 2;
        log_n++;
    }

    vector<vector<ll>> up(log_n, vector<ll>(n + 1, 0));

    for (ll i = 2; i <= n; i++) {
        cin >> up[0][i];
    }

    for (ll j = 1; j < log_n; j++) {
        for (ll u = 1; u <= n; u++) {
            up[j][u] = up[j - 1][up[j - 1][u]];
        }
    }

    for (ll i = 0; i < q; i++) {
        ll x, k;
        cin >> x >> k;

        // Binary Lifting
        ll atual = x;
        ll j = 0;
        while (k > 0 && atual != 0) {
            if (k % 2 == 1) {
                atual = up[j][atual];
            }
            k /= 2;
            j++;
        }

        if (atual == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << atual << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
