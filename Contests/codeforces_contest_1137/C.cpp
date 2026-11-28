#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> p(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<ll> menor_esq(n, -1);
    vector<ll> menor_dir(n, n);
    stack<ll> s;

    for (ll i = 0; i < n; i++) {
        while (!s.empty() && p[s.top()] > p[i]) {
            s.pop();
        }
        if (!s.empty()) {
            menor_esq[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    for (ll i = n - 1; i >= 0; i--) {
        while (!s.empty() && p[s.top()] > p[i]) {
            s.pop();
        }
        if (!s.empty()) {
            menor_dir[i] = s.top();
        }
        s.push(i);
    }

    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll a = i - menor_esq[i];
        ll b = menor_dir[i] - i;

        if (a == 1 || b == 1) {
            res += a + b - 1;
        }
        else {
            res += 2;
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}