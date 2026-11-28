#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        // Produto vetorial (p2 - p1) x (p3 - p1)
        ll pv = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

        if (pv > 0) {
            cout << "LEFT\n";
        }
        else if (pv < 0) {
            cout << "RIGHT\n";
        }
        else {
            cout << "TOUCH\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
