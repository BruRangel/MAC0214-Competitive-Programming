#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // mapa que guarda (soma, par de índices que produz a soma)
    unordered_map<ll, pair<ll, ll>> pares;

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll resto = x - a[i] - a[j];

            auto match = pares.find(resto);

            if (match != pares.end()) {
                ll p = match->second.first;
                ll q = match->second.second;

                cout << p + 1 << " "
                << q + 1 << " "
                << i + 1 << " "
                << j + 1 << "\n";

                return;
            }
        }

        for (ll p = 0; p < i; p++) {
            ll soma = a[p] + a[i];
            pares[soma] = {p, i};
        }
    }

    cout << "IMPOSSIBLE" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}