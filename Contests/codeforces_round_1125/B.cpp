#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    stack<ll> pilha;

    vector<bool> imprimiu(n);
    for (ll i = 0; i < n; i++) {
        imprimiu[i] = false;
    }

    for (ll i = 0; i < size(s); i++) {
        char c = s[i];
        if (c == '1') {
            pilha.push(i);
        }
        else if (c == '2') {
            if (!pilha.empty()) {
                ll current = pilha.top();
                imprimiu[current] = true;
                pilha.pop();
            }
            else {
                imprimiu[i] = true;
            }
        }
        else if (c == '3') {
            imprimiu[i] = true;
        }
    }

    ll count = 0;
    for (ll i = 0; i < n; i++) {
        if (imprimiu[i] == false) {
            count++;
        }
    }

    cout << count << "\n";

    for (ll i = 0; i < n; i++) {
        if (!imprimiu[i]) {
            cout << i+1 << " ";
        }
    }

    cout << "\n";
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
