#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    const ll MOD = 1e9 + 7;

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[v] = número de arrays válidos até a posição atual terminando em v
    // Usamos tamanho m + 2 para acessar dp[v - 1] e dp[v + 1] sem checar bordas
    vector<ll> dp(m + 2, 0), ndp(m + 2, 0);

    // Inicialização da primeira posição
    if (a[0] == 0) {
        for (ll v = 1; v <= m; v++) {
            dp[v] = 1;
        }
    } else {
        dp[a[0]] = 1;
    }

    for (ll i = 1; i < n; i++) {
        fill(ndp.begin(), ndp.end(), 0);

        if (a[i] == 0) {
            for (ll v = 1; v <= m; v++) {
                ndp[v] = (dp[v - 1] + dp[v] + dp[v + 1]) % MOD;
            }
        } else {
            ll v = a[i];
            ndp[v] = (dp[v - 1] + dp[v] + dp[v + 1]) % MOD;
        }

        dp.swap(ndp);
    }

    ll ans = 0;
    for (ll v = 1; v <= m; v++) {
        ans = (ans + dp[v]) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
