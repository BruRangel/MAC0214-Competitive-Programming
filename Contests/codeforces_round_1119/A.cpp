#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    string fields;
    cin >> fields;

    ll n_nhoj = 0;

    for (ll i = 0; i < n; i += k) {
        bool all_nhoj = true;

        for (ll j = i; j < i + k; j++) {
            if (fields[j] == '0') {
                all_nhoj = false;
                break;
            }
        }

        if (all_nhoj) {
            n_nhoj++;
        }
    }

    cout << n_nhoj << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}