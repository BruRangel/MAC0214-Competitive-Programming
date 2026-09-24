#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(const pair<ll ,ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

void solve() {
    ll n; cin >> n;

    vector<pair<ll,ll>> movies(n);

    for (ll i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    
    sort(movies.begin(), movies.end(), compare);

    ll current_end_time = 0;
    ll n_movies = 0;

    for (ll i = 0; i < n; i++) {
        if (movies[i].first >= current_end_time) {
            n_movies++;
            current_end_time = movies[i].second;
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
