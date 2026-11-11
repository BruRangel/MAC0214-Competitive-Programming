#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    ll sum = 0;

    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        sum += p[i];
    }

    ll res = LLONG_MAX;

    // 1 << n = 2^n
    for (int mask = 0; mask < (1 << n); ++mask) {
        ll sum_A = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum_A += p[i];
            }
        }

        ll sum_B = sum - sum_A;
        res = min (res, llabs(sum_A - sum_B));
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
