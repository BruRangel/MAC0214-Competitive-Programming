#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Índices para busca binária
    ll l = *max_element(a.begin(), a.end());
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r += a[i];
    }

    ll res = 0;

    if (k == 1) {
        res = r;
        cout << res << "\n";
        return 0;
    }

    while (l <= r) {
        ll m = (l + r)/2;
        ll n_subarrays = 1;
        ll soma_atual = a[0];

        for (int i = 1; i < n; i++) {
            if (soma_atual + a[i] <= m) {
                soma_atual += a[i];
            }
            else {
                n_subarrays++;
                soma_atual = 0;
                soma_atual += a[i];
            }
        }

        if (n_subarrays <= k) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << res << "\n";
    return 0;
}
