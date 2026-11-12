#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll mediana = a[n / 2];

    ll custo = 0;
    for (ll i = 0; i < n; i++) {
        custo += abs(a[i] - mediana);
    }

    cout << custo << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    
    return 0;
}