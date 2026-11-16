#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> x(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<ll> dp;

    for (ll i = 0; i < n; i++) {
        // posição do primeiro elemento em dp que é >= x[i];
        ll pos = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();

        if (pos == dp.size()) {
            dp.push_back(x[i]); // estende a LIS
        }
        else {
            dp[pos] = x[i];
        }
    }

    cout << dp.size() << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}