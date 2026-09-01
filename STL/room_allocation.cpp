#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> customers;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        customers.push_back({a, b});
    }

    sort(customers.begin(), customers.end());

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> heap;
    ll nrooms = 1;
    heap.push({customers[0].second, nrooms});

    for (ll i = 1; i < n; i++) {
        if (customers[i].first > heap.top().first) {
            ll room = heap.top().second;
            heap.pop();
            heap.push({customers[i].second, room});
        }
        else {
            nrooms++;
            heap.push({customers[i].second, nrooms});
        }
    }
}

int main() {
    solve();
    return 0;
}