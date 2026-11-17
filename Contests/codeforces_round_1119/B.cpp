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

    ll n_pares = 0;
    ll n_impares = 0;

    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            n_pares++;
        }
        else {
            n_impares++;
        }
    }

    ll quatro_zero = 0;
    ll quatro_dois = 0;

    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (a[i] % 4 == 0) {
                quatro_zero++;
            }
            else {
                quatro_dois++;
            }
        }
    }

    ll maior = max(quatro_zero, quatro_dois);
    ll res = max(n_impares, maior);

    cout << res << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
