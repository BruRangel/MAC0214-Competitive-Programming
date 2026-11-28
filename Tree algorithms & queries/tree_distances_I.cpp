#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bfs(ll start, const vector<vector<ll>>& adj, vector<ll>& dist) {
    fill(dist.begin(), dist.end(), -1);
    queue<ll> q;

    dist[start] = 0;
    q.push(start);

    ll mais_distante = start;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();

        if (dist[u] > dist[mais_distante]) {
            mais_distante = u;
        }

        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return mais_distante;
}

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> dist_u(n + 1);
    vector<ll> dist_v(n + 1);

    ll u = bfs(1, adj, dist_u);
    ll v = bfs(u, adj, dist_u);
    bfs(v, adj, dist_v);

    // A maior dist a partir de cada nó é sempre até uma das extremidades do diâmetro
    for (ll i = 1; i <= n; i++) {
        cout << max(dist_u[i], dist_v[i]);
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
