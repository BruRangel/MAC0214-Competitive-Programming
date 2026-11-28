#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll exp_binaria(ll a, ll b) {
    a %= MOD;
    ll res = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }

    return res;
}

void solve() {
    ll n;
    cin >> n;

    ll qtd = 1;
    ll soma = 1;
    ll prod = 1;
    ll qtd_exp = 1;

    for (ll i = 0; i < n; i++) {
        ll x, k;
        cin >> x >> k;

        qtd = (qtd * (k + 1)) % MOD;

        // Soma de divisores: (x^(k+1) - 1) / (x - 1)
        ll num = (exp_binaria(x, k + 1) - 1 + MOD) % MOD;
        ll den = exp_binaria(x - 1, MOD - 2);
        ll fator_soma = (num * den) % MOD;
        soma = (soma * fator_soma) % MOD;

        // Produto de divisores: prod^(k+1) * x^((k*(k+1)/2) * qtd_exp)
        ll soma_exp = (k * (k + 1) / 2) % (MOD - 1);
        ll bloco = exp_binaria(x, (soma_exp * qtd_exp) % (MOD - 1));
        prod = (exp_binaria(prod, k + 1) * bloco) % MOD;

        qtd_exp = (qtd_exp * (k + 1)) % (MOD - 1);
    }

    cout << qtd << " " << soma << " " << prod << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
