#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<ll> score(1 << n, 0);

    for (ll mask = 1; mask < (1 << n); mask++) {
        ll first_rabbit = -1;
        for (ll i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                first_rabbit = i;
                break;
            }
        }

        ll rest_mask = mask ^ (1 << first_rabbit);

        ll extra_points = 0;
        for (ll j = 0; j < n; j++) {
            if (rest_mask & (1 << j)) {
                extra_points += a[first_rabbit][j];
            }
        }

        score[mask] = score[rest_mask] + extra_points;
    }

    vector<ll> dp(1 << n, -1e18);
    dp[0] = 0;

    for (ll mask = 1; mask < (1 << n); mask++) {
        for (ll sub = mask; sub > 0; sub = (sub - 1) & mask) {
            ll rest = mask ^ sub;
            
            ll current_score = score[sub] + dp[rest];
            
            if (current_score > dp[mask]) {
                dp[mask] = current_score;
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