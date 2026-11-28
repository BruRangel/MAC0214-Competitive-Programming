#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void add(ll k, ll delta, ll tam, vector<ll>& tree) {
    k += tam;
    tree[k] += delta;
    k /= 2;

    while (k >= 1) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
        k /= 2;
    }
}

ll sum(ll a, ll b, ll tam, vector<ll>& tree) {
    a += tam;
    b += tam;
    ll s = 0;

    while (a <= b) {
        if (a % 2 == 1) {
            s += tree[a];
            a++;
        }
        if (b % 2 == 0) {
            s += tree[b];
            b--;
        }
        a /= 2;
        b /= 2;
    }

    return s;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> val(n);
    for (ll i = 0; i < n; i++) {
        cin >> val[i];
    }

    ll tam = 1;
    while (tam < n) {
        tam *= 2;
    }

    vector<ll> tree(2 * tam, 0);

    for (ll i = 0; i < q; i++) {
        ll tipo;
        cin >> tipo;

        if (tipo == 1) {
            ll a, b, u;
            cin >> a >> b >> u;

            add(a - 1, u, tam, tree);
            if (b < n) {
                add(b, -u, tam, tree);
            }
        }
        else {
            ll k;
            cin >> k;
            cout << val[k - 1] + sum(0, k - 1, tam, tree) << "\n";
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
