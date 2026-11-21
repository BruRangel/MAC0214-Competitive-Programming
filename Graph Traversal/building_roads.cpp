#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<ll> comps;

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            comps.push_back(i);

            queue<ll> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                for (ll v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    ll k = comps.size() - 1;
    cout << k << "\n";

    for (ll i = 0; i < k; i++) {
        cout << comps[i] << " " << comps[i + 1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
