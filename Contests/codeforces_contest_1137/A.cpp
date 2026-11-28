#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x;
    cin >> x;
    ll y = 0;
    while (x % 2 == 0) {
        x /= 2;
        y++;
    }

    if (y == 1) {
        cout << "No" << "\n";
    }
    else {
        cout << "Yes" << "\n";
    }
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
