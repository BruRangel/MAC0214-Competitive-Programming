#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n ; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    ll lp = 0;
    ll rp = n-1;

    while (lp < rp) {
        ll sum = a[lp].first + a[rp].first;
        if (sum == x) {
            cout << a[lp].second << " " << a[rp].second << "\n";
            return;
        }
        else if (sum > x) {
            rp--;
        }
        else {
            lp++;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
