#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vector<vector<char>> moves(n, vector<char>(m, ' '));
    queue<pair<ll, ll>> q;
    pair<ll, ll> start;

    for (ll i = 0; i < n; i++) {
        cin >> grid[i];
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // 'A' entra na fila por último para que os monstros tenham prioridade em cada turno
    q.push(start);

    pair<ll, ll> escape = {-1, -1};

    while (!q.empty()) {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();

        if (grid[x][y] == 'A') {
            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                escape = {x, y};
                break;
            }
        }

        // Esquerda
        if (y - 1 >= 0 && grid[x][y - 1] == '.') {
            grid[x][y - 1] = grid[x][y];
            if (grid[x][y] == 'A') moves[x][y - 1] = 'L';
            q.push({x, y - 1});
        }
        // Direita
        if (y + 1 < m && grid[x][y + 1] == '.') {
            grid[x][y + 1] = grid[x][y];
            if (grid[x][y] == 'A') moves[x][y + 1] = 'R';
            q.push({x, y + 1});
        }
        // Cima
        if (x - 1 >= 0 && grid[x - 1][y] == '.') {
            grid[x - 1][y] = grid[x][y];
            if (grid[x][y] == 'A') moves[x - 1][y] = 'U';
            q.push({x - 1, y});
        }
        // Baixo
        if (x + 1 < n && grid[x + 1][y] == '.') {
            grid[x + 1][y] = grid[x][y];
            if (grid[x][y] == 'A') moves[x + 1][y] = 'D';
            q.push({x + 1, y});
        }
    }

    if (escape.first == -1) {
        cout << "NO\n";
    } 
    else {
        cout << "YES\n";

        string path = "";
        ll x = escape.first;
        ll y = escape.second;

        while (x != start.first || y != start.second) {
            char move = moves[x][y];
            path += move;

            if (move == 'L') y++;
            else if (move == 'R') y--;
            else if (move == 'U') x++;
            else if (move == 'D') x--;
        }

        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        cout << path << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}