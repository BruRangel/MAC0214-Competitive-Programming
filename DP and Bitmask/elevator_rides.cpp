#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> weights(n);
    for (ll i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<pair<ll, ll>> dp(1 << n, {1e9, 1e9});
    dp[0] = {1, 0};

    for (ll mask = 0; mask < (1 << n); mask++) {
        for (ll i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                ll next_mask = mask | (1 << i);
                
                ll viagens = dp[mask].first;
                ll current_weight = dp[mask].second;

                ll novas_viagens, novo_peso;

                if (current_weight + weights[i] <= x) {
                    novas_viagens = viagens;
                    novo_peso = current_weight + weights[i];
                } 
                else {
                    novas_viagens = viagens + 1;
                    novo_peso = weights[i];
                }

                if (novas_viagens < dp[next_mask].first) {
                    dp[next_mask] = {novas_viagens, novo_peso};
                } else if (novas_viagens == dp[next_mask].first) {
                    if (novo_peso < dp[next_mask].second) {
                        dp[next_mask] = {novas_viagens, novo_peso};
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}