#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(const pair<ll ,ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

void solve() {
    ll n; cin >> n;
    ll k; cin >> k;

    vector<pair<ll,ll>> movies(n);

    for (ll i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    
    sort(movies.begin(), movies.end(), compare);

    multiset<ll> end_times;
    for (ll i = 0; i < k; i++) {
        end_times.insert(0);
    }

    ll n_movies = 0;

    for (auto &m : movies) {
        ll start = m.first;
        ll end = m.second;

        auto it = end_times.upper_bound(start);

        if (it != end_times.begin()) {
            it--; // maior end_time que é menor que end
            end_times.erase(it);
            end_times.insert(end);
            n_movies++;
        }
    }

    cout << n_movies << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
