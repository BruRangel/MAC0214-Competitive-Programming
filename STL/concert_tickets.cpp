#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;

    multiset<ll> tickets;
    for (ll i = 0; i < n; i++) {
        ll ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    for (ll i = 0; i < m; i++) {
        ll price_limit;
        cin >> price_limit;

        auto up = tickets.upper_bound(price_limit);

        if (up == tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            up--;
            cout << *up << "\n";
            tickets.erase(up);
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