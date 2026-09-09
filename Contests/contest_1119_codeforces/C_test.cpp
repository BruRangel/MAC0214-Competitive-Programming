#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll first_1 = -1, last_1 = -1;
    ll first_mu = -1, last_mu = -1;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            if (first_1 == -1) first_1 = i;
            last_1 = i;
        } else if (a[i] == -1) {
            if (first_mu == -1) first_mu = i;
            last_mu = i;
        }
    }

    if (first_1 == -1) {
        // Não existem "1"s no array
        if (first_mu != -1 && first_mu != last_mu) {
            a[first_mu] = 1;
            a[last_mu] = 1;
        }
    } else {
        // Existem "1"s, expandir as pontas se possível
        if (first_mu != -1 && first_mu < first_1) {
            a[first_mu] = 1;
        }
        if (last_mu != -1 && last_mu > last_1) {
            a[last_mu] = 1;
        }
    }

    // Todos os outros "-1" que sobraram no meio devem virar "0"
    for (ll i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Otimização de I/O para evitar Time Limit Exceeded
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
