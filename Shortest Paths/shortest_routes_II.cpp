#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (ll i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        // Estradas bidirecionais, mantém a menor caso existam arestas múltiplas
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Algoritmo de Floyd-Warshall
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;
            for (ll j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;

        if (dist[a][b] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[a][b] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
