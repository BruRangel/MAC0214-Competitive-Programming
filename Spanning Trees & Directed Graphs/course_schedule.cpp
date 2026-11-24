#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

// precisamos encontrar uma ordenação topológica
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    vector<ll> grau_de_entrada(n + 1, 0);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        grau_de_entrada[b]++;
    }

    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        if (grau_de_entrada[i] == 0) {
            q.push(i);
        }
    }

    vector<ll> ord;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        ord.push_back(u);

        for (ll v : adj[u]) {
            grau_de_entrada[v]--;
            if (grau_de_entrada[v] == 0) {
                q.push(v);
            }
        }
    }

    if (ord.size() < n) {
        cout << "IMPOSSIBLE\n";
    } 
    else {
        for (ll i = 0; i < n; i++) {
            cout << ord[i];
            if (i + 1 < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}