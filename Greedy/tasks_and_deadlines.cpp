#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(const pair<ll ,ll> &a, const pair<ll, ll> &b) {
    return a.first < b.first;
}

void solve() {
    ll n; cin >> n;

    vector<pair<ll,ll>> tasks(n);

    for (ll i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    
    sort(tasks.begin(), tasks.end(), compare);

    ll current_time = 0;
    ll reward = 0;

    for (ll i = 0; i < n; i++) {
        current_time += tasks[i].first;
        reward += tasks[i].second - current_time;
    }

    cout << reward << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
