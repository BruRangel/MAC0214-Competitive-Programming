#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    ll sum = n * (n+1) / 2;

    if (sum % 2 != 0) {
        cout << 0 << "\n";
        return;
    }

    ll target = sum / 2;

    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll s = target; s >= i; s--) {
            dp[s] = (dp[s] + dp[s-i]) % MOD;
        }
    }

    ll mult_inv_2 = (MOD + 1) / 2;

    // simula uma divisão por 2
    cout << (dp[target] * mult_inv_2) % MOD << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}