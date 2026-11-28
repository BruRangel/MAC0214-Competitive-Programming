#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> prefix_function(string s) {
    ll n = s.size();
    vector<ll> pi(n, 0);

    for (ll i = 1; i < n; i++) {
        ll sz = pi[i - 1];
        while (sz > 0 && s[sz] != s[i]) {
            sz = pi[sz - 1];
        }
        if (s[sz] == s[i]) {
            sz++;
        }
        pi[i] = sz;
    }

    return pi;
}

void solve() {
    string s;
    cin >> s;

    ll n = s.size();
    vector<ll> pi = prefix_function(s);

    vector<ll> bordas;
    ll k = pi[n - 1];
    while (k > 0) {
        bordas.push_back(k);
        k = pi[k - 1];
    }

    reverse(bordas.begin(), bordas.end());
    for (ll i = 0; i < bordas.size(); i++) {
        cout << bordas[i];
        if (i + 1 < bordas.size()) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
