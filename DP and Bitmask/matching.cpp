#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<ll> bits(1 << n, 0);
    for (ll mask = 1; mask < (1 << n); mask++) {
        bits[mask] = bits[mask / 2] + (mask % 2);
    }

    vector<ll> dp(1 << n, 0);
    dp[0] = 1;

    for (ll mask = 0; mask < (1 << n); mask++) {
        ll k = bits[mask];

        if (k == n) continue;

        for (ll j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                if (a[k][j] == 1) {
                    ll next_mask = mask | (1 << j);
                    dp[next_mask] = (dp[next_mask] + dp[mask]) % MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}