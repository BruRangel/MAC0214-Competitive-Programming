#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multiset<ll> lower, upper;
    ll l_size = (k+1)/2;
    ll u_size = k/2;

    for (ll i = 0; i < k; ++i) {
        lower.insert(a[i]);
    }

    while ((ll)lower.size() > l_size) {
        auto it = prev(lower.end());
        upper.insert(*it);
        lower.erase(it);
    }

    while (!lower.empty() && !upper.empty() && *lower.rbegin() > *upper.begin()) {
        ll mx = *lower.rbegin();
        ll mn = *upper.begin();
        lower.erase(prev(lower.end()));
        upper.erase(upper.begin());
        lower.insert(mn);
        upper.insert(mx);
    }

    cout << *lower.rbegin() << " ";

    for (ll i = k; i < n; ++i) {
        ll pop = a[i-k];
        auto it_lower = lower.find(pop);
        if (it_lower != lower.end()) {
            lower.erase(it_lower);
        }
        else {
            auto it_upper = upper.find(pop);
            upper.erase(it_upper);
        }

        ll push = a[i];
        lower.insert(push);

        while ((ll)lower.size() > l_size) {
            auto it = prev(lower.end());
            upper.insert(*it);
            lower.erase(it);
        }
        while ((ll)lower.size() < l_size) {
            auto it = upper.begin();
            lower.insert(*it);
            upper.erase(it);
        }

        while (!lower.empty() && !upper.empty() && *lower.rbegin() > *upper.begin()) {
            ll mx = *lower.rbegin();
            ll mn = *upper.begin();
            lower.erase(prev(lower.end()));
            upper.erase(upper.begin());
            lower.insert(mn);
            upper.insert(mx);
        }

        cout << *lower.rbegin() << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}