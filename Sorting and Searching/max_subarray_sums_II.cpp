#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> prefixo(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        ll current;
        cin >> current;
        prefixo[i] = prefixo[i - 1] + current;
    }

    multiset<ll> ms;
    ll ans = -1e18; // Inicializa com um valor muito pequeno, pois os números podem ser negativos

    for (ll r = a; r <= n; r++) {
        // Adiciona o índice i = r - a na janela
        ms.insert(prefixo[r - a]);

        // Remove o índice i = r - b - 1 se ele já tiver saído da janela
        if (r - b - 1 >= 0) {
            ms.erase(ms.find(prefixo[r - b - 1]));
        }

        // O menor prefixo válido é o primeiro elemento do multiset
        ans = max(ans, prefixo[r] - *ms.begin());
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