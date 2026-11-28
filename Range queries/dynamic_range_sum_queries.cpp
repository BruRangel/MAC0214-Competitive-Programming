#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Atualiza o valor na posição k para x na Segment Tree
void update(ll k, ll x, ll tam, vector<ll>& tree) {
    k += tam;
    tree[k] = x;
    k /= 2;

    while (k >= 1) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
        k /= 2;
    }
}

// Retorna a soma no intervalo [a, b]
ll sum(ll a, ll b, ll tam, const vector<ll>& tree) {
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

    // Arredonda o tamanho para a próxima potência de 2 (CPH 9.3)
    ll tam = 1;
    while (tam < n) {
        tam *= 2;
    }

    vector<ll> tree(2 * tam, 0);

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        update(i, x, tam, tree);
    }

    for (ll i = 0; i < q; i++) {
        ll tipo;
        cin >> tipo;

        if (tipo == 1) {
            ll k, u;
            cin >> k >> u;
            update(k - 1, u, tam, tree);
        }
        else {
            ll a, b;
            cin >> a >> b;
            cout << sum(a - 1, b - 1, tam, tree) << "\n";
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
