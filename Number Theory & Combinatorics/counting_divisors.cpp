#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> queries(n);
    ll max_x = 0;
    for (ll i = 0; i < n; i++) {
        cin >> queries[i];
        max_x = max(max_x, queries[i]);
    }

    // Pré-computa a quantidade de divisores de cada número até max_x
    vector<ll> divisores(max_x + 1, 0);
    for (ll i = 1; i <= max_x; i++) {
        for (ll j = i; j <= max_x; j += i) {
            divisores[j]++;
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << divisores[queries[i]] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
