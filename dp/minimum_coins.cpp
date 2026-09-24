#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

// dp == divide & conquer com uma tabela
// dp[i] = num mínimo de moedas para somar i
// dp[0] = 0
// dp[i] = min(dp[i - c] + 1) para cada c <= i

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x + 1, INF);
    dp[0] = 0;

    for (ll i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i >= c) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[x] == INF) {
        cout << -1 << "\n";
    }
    else {
        cout << dp[x] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
