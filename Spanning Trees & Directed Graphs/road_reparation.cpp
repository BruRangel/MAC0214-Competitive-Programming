#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5+10;
const ll MAXM = 2e5+10;

ll parent[MAXN], sz[MAXN];

ll find(ll a){
    if (parent[a] == a) 
        return a;
    return parent[a] = find(parent[a]);
}

bool join(ll a, ll b){
    ll raiz_a = find(a), raiz_b = find(b);
    if (raiz_a == raiz_b) return 0;
    if (sz[raiz_a] >= sz[raiz_b]){
        parent[raiz_b] = raiz_a;
        sz[raiz_a] += sz[raiz_b];
    }
    else {
        parent[raiz_a] = raiz_b;
        sz[raiz_b] += sz[raiz_a];
    }
    return 1;
}

struct edge {
    ll u, v, w;
    edge(): u(0), v(0), w(0){}
    edge(ll u_, ll v_, ll w_): u(u_), v(v_), w(w_){}
};

edge edges[MAXM];

void solve() {
    ll n, m; cin >> n >> m;
    for (ll i = 0; i < n; i++) 
        parent[i] = i, sz[i] = 1;
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        edges[i] = {u, v, w};
    }
    sort(edges, edges + m, [&](edge a, edge b){
        return a.w < b.w;
    });
    ll cost = 0;
    for (ll i = 0; i < m; i++) {
        auto[u, v, w] = edges[i];
        if(join(u, v)) 
            cost += w;
    }
    ll root = find(0);
    if (sz[root] != n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    } 
    cout << cost << endl; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}