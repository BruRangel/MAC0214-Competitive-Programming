#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a;
    for (ll i = 0; i < n; i++) {
        ll curr;
        cin >> curr;
        a.push_back(curr);
    }

    // Queremos encontrar o maior intervalo que possua um "1" ou "-1" em ambas as bordas
    // e não possua nenhum "1" no resto do intervalo.
    vector<ll> uns;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1) {
            uns.push_back(i);
        }
    }

    if(uns.empty()) {
        ll first_mu = -1;
        ll last_mu = -1;

        for (ll i = 0; i < n; i++) {
            if (a[i] == -1) {
                first_mu = i;
            }
        }

        for (ll i = n - 1; i >= 0; i--) {
            if (a[i] == -1) {
                last_mu = i;
            }
        }

        if (first_mu == last_mu) {
            cout << 0 << "\n";
            return;
        }
    }

}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
