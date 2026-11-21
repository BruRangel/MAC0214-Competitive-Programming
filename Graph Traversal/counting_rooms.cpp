#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    ll n, m;
    if (!(cin >> n >> m)) return;

    vector<string> mapa(n);
    for (ll i = 0; i < n; i++) {
        cin >> mapa[i];
    }

    ll rooms = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (mapa[i][j] == '.') {
                rooms++;
                queue<pair<ll, ll>> q;
                q.push({i, j});
                mapa[i][j] = '#';

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    // Cima
                    if (r - 1 >= 0 && mapa[r - 1][c] == '.') {
                        mapa[r - 1][c] = '#';
                        q.push({r - 1, c});
                    }
                    // Baixo
                    if (r + 1 < n && mapa[r + 1][c] == '.') {
                        mapa[r + 1][c] = '#';
                        q.push({r + 1, c});
                    }
                    // Esquerda
                    if (c - 1 >= 0 && mapa[r][c - 1] == '.') {
                        mapa[r][c - 1] = '#';
                        q.push({r, c - 1});
                    }
                    // Direita
                    if (c + 1 < m && mapa[r][c + 1] == '.') {
                        mapa[r][c + 1] = '#';
                        q.push({r, c + 1});
                    }
                }
            }
        }
    }

    cout << rooms << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}