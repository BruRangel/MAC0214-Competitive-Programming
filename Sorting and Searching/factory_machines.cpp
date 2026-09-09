#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool can_produce(ll s, vector<ll> &k, ll t) {
    ll produced = 0;

    for (ll machine : k) {
        produced += s/machine;

        if (produced >= t) {
            return true;
        }
    }

    return false;
}

ll bin_search(vector<ll> &k, ll t, ll left, ll right) {
    if (left == right) {
        return left;
    }

    ll mid = left + (right - left) / 2;

    if (can_produce(mid, k ,t)) {
        return bin_search(k, t, left, mid);
    }
    else {
        return bin_search(k, t, mid + 1, right);
    }
}

void solve() {
    // The factory have n machines to make products.
    // We wanna make a total of t products
    // We'll have n numbers, k1,...,kn, the timen needed to make a product using each machine
    // Output the minimum time needed to make t products

    ll n, t;
    cin >> n >> t;

    vector<ll> k;

    for (ll i = 0; i < n; i++) {
        ll ki; cin >> ki;
        k.push_back(ki);
    }

    sort(k.begin(), k.end());

    // k is now ordered
    ll left = 0;
    ll right = t * k[0];

    ll res = bin_search(k, t, left, right);
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
