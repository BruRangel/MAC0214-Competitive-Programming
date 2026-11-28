#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(n)
vector<ll> prefix_function(string s) {
    ll n = s.size();
    vector<ll> pi(n);
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

// O(n)
vector<ll> kmp(string t, string p) {
    string s = p+"#";
    vector<ll> pi = prefix_function(s);
    vector<ll> ocorrencias;
    ll j = 0;
    for (ll i = 0; i < t.size(); i++) {
        while (j > 0 && s[j] != t[i]) {
            j = pi[j - 1];
        }
        if (s[j] == t[i]) {
            j++;
        }
        if (j == p.size()) {
            ocorrencias.push_back(i - p.size() + 1);
        }
    }
    return ocorrencias;
}

void solve() {
    string t, p;
    cin >> t >> p;
    cout << kmp(t, p).size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
