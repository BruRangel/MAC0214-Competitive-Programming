#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll total_zeros = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            total_zeros++;
        }
    }

    if (s[0] == '1') {
        cout << total_zeros << "\n";
        return;
    }

    ll custo_atual = total_zeros;
    ll menor_custo = custo_atual;

    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            custo_atual--; 
        } else {
            custo_atual++;
        }
        
        menor_custo = min(menor_custo, custo_atual);
    }

    cout << menor_custo << "\n";
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