#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> x(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<ll> length(n);
    for (ll k = 0; k < n; k++) {
        length[k] = 1;
        for (ll i = 0; i < k; i++) {
            if (x[i] < x[k]) {
                length[k] = max(length[k], length[i] + 1);
            }
        }
    }

    ll max = 0;
    for (ll i = 0; i < n; i++) {
        if (length[i] > max) {
            max = length[i];
        }
    }

    cout << max << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}