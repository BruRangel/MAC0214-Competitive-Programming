#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll u, const vector<vector<ll>>& adj, vector<ll>& sub) {
    sub[u] = 0;
    for (ll v : adj[u]) {
        dfs(v, adj, sub);
        // Cada filho contribui com ele mesmo + seus subordinados
        sub[u] += 1 + sub[v];
    }
}

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 2; i <= n; i++) {
        ll chefe;
        cin >> chefe;
        adj[chefe].push_back(i);
    }

    vector<ll> sub(n + 1, 0);
    dfs(1, adj, sub);

    for (ll i = 1; i <= n; i++) {
        cout << sub[i];
        if (i < n) {
            cout << " ";
        }
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
