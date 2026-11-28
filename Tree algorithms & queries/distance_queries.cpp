#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Encontra o LCA (CPH 18.3)
ll lca(ll a, ll b, ll log_n, const vector<ll>& prof, const vector<vector<ll>>& up) {
    if (prof[a] < prof[b]) {
        swap(a, b);
    }

    ll diff = prof[a] - prof[b];
    ll j = 0;
    while (diff > 0) {
        if (diff % 2 == 1) {
            a = up[j][a];
        }
        diff /= 2;
        j++;
    }

    if (a == b) {
        return a;
    }

    for (ll k = log_n - 1; k >= 0; k--) {
        if (up[k][a] != up[k][b]) {
            a = up[k][a];
            b = up[k][b];
        }
    }

    return up[0][a];
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll pot = 1;
    ll log_n = 1;
    while (pot <= n) {
        pot *= 2;
        log_n++;
    }

    vector<vector<ll>> up(log_n, vector<ll>(n + 1, 0));
    vector<ll> prof(n + 1, -1);

    // BFS
    queue<ll> fila;
    prof[1] = 0;
    fila.push(1);

    while (!fila.empty()) {
        ll u = fila.front();
        fila.pop();

        for (ll v : adj[u]) {
            if (prof[v] == -1) {
                prof[v] = prof[u] + 1;
                up[0][v] = u;
                fila.push(v);
            }
        }
    }

    for (ll j = 1; j < log_n; j++) {
        for (ll u = 1; u <= n; u++) {
            up[j][u] = up[j - 1][up[j - 1][u]];
        }
    }

    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;

        ll anc = lca(a, b, log_n, prof, up);
        cout << prof[a] + prof[b] - 2 * prof[anc] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
