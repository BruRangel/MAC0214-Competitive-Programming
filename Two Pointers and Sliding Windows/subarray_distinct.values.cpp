#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = 0;
    ll L = 0;

    map<ll, ll> freq;

    for (ll R = 0; R < n; R++) {
        freq[a[R]]++;

        while ((ll)freq.size() > k) {
            freq[a[L]]--;

            if (freq[a[L]] == 0) {
                freq.erase(a[L]);
            }

            L++;
        }

        res += R - L + 1;
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}