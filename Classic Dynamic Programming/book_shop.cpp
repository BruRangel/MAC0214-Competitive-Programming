#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> h(n), s(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<ll> dp(x + 1, 0);

    for (ll i = 0; i < n; i++) {
        for (ll orcamento = x; orcamento >= h[i]; orcamento--) {
            dp[orcamento] = max(dp[orcamento], dp[orcamento - h[i]] + s[i]);
        }
    }

    cout << dp[x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
