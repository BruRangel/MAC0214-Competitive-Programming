#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[u][0]: menor custo até u sem usar o cupom
    // dist[u][1]: menor custo até u já tendo usado o cupom
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, usou] = pq.top();
        pq.pop();

        if (d > dist[u][usou]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v][usou]) {
                dist[v][usou] = d + w;
                pq.push({dist[v][usou], v, usou});
            }

            if (usou == 0 && d + w / 2 < dist[v][1]) {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
