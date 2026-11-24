#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll u, const vector<vector<ll>>& adj, vector<bool>& visitado) {
    visitado[u] = true;
    for (ll v : adj[u]) {
        if (!visitado[v]) {
            dfs(v, adj, visitado);
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    vector<vector<ll>> adj_rev(n + 1);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    // 1 DFS: verifica se a cidade 1 alcança todas as outras
    vector<bool> visitado(n + 1, false);
    dfs(1, adj, visitado);

    for (ll i = 1; i <= n; i++) {
        if (!visitado[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return;
        }
    }

    // 2 DFS no grafo reverso: verifica se todas as cidades alcançam a cidade 1
    fill(visitado.begin(), visitado.end(), false);
    dfs(1, adj_rev, visitado);

    for (ll i = 1; i <= n; i++) {
        if (!visitado[i]) {
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
