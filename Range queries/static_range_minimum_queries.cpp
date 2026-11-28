#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 200005;
const ll LOG = 19;

// st[i][j] guarda o minimo em [i, i + 2^j - 1]
ll st[MAXN][LOG];
ll lg[MAXN];

void solve() {
    ll n, q;
    cin >> n >> q;

    for (ll i = 1; i <= n; i++) {
        cin >> st[i][0];
    }

    lg[1] = 0;
    for (ll i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    for (ll j = 1; j < LOG; j++) {
        for (ll i = 1; i + (1LL << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;

        ll k = lg[r - l + 1];
        // dois blocos de tamanho 2^k cobrindo [l, r]
        cout << min(st[l][k], st[r - (1LL << k) + 1][k]) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}