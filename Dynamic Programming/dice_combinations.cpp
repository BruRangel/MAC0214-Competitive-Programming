#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const ll mod = 1e9 + 7; 

ll nways(ll n) {
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll c = 1; c <= 6; c++) {
            if (i - c >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % mod;
            }
        }
    }

    return dp[n];
}

void solve() {
    ll n;
    cin >> n;
    cout << nways(n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
