#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    
    vector<tuple<ll, ll, ll>> customers;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    sort(customers.begin(), customers.end());

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> heap;
    ll nrooms = 1;
    
    vector<ll> ans(n);
    
    heap.push({get<1>(customers[0]), nrooms});
    ans[get<2>(customers[0])] = nrooms;

    for (ll i = 1; i < n; i++) {
        auto [chegada, saida, id] = customers[i];
        
        if (chegada > heap.top().first) {
            ll room = heap.top().second;
            heap.pop();
            heap.push({saida, room});
            ans[id] = room;
        }
        else {
            nrooms++;
            heap.push({saida, nrooms});
            ans[id] = nrooms;
        }
    }

    cout << nrooms << "\n";
    
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}