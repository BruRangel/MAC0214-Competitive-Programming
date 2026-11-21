#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 100005;

vector<ll> adj[MAXN];
bool visited[MAXN];
ll parent[MAXN];
ll cycle_start = -1, cycle_end = -1;

bool dfs(ll u, ll p) {
    visited[u] = true;
    for (ll v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
        parent[v] = u;
        if (dfs(v, u)) return true;
    }
    return false;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for (ll curr = cycle_end; curr != cycle_start; curr = parent[curr]) {
            cycle.push_back(curr);
        }
        cycle.push_back(cycle_start);

        cout << cycle.size() << "\n";
        for (ll i = 0; i < (ll)cycle.size(); i++) {
            cout << cycle[i] << (i + 1 == (ll)cycle.size() ? "" : " ");
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