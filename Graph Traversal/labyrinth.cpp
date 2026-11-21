#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

bool visited[1013][1013];
ll dist[1013][1013];
char moves[1013][1013];
queue<pair<ll, ll>> q;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    pair<ll, ll> start;
    pair<ll, ll> end;

    vector<vector<char>> labyrinth(n, vector<char>(m));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> labyrinth[i][j];

            if (labyrinth[i][j] == 'A') start = {i, j};
            if (labyrinth[i][j] == 'B') end = {i, j};
        }
    }

    for (ll i = 0; i < 1013; i++) {
        for (ll j = 0; j < 1013; j++) {
            visited[i][j] = false;
            dist[i][j] = -1;
        }
    }

    dist[start.first][start.second] = 0;
    visited[start.first][start.second] = true;
    q.push(start);

    // BFS
    while(!q.empty()) {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();

        if (x == end.first && y == end.second) {
            break;
        }

        if (y - 1 >= 0 && !visited[x][y - 1] && labyrinth[x][y - 1] != '#') {
            visited[x][y - 1] = true;
            dist[x][y - 1] = dist[x][y] + 1;
            moves[x][y - 1] = 'L';
            q.push({x, y - 1});
        }

        if (y + 1 < m && !visited[x][y + 1] && labyrinth[x][y + 1] != '#') {
            visited[x][y + 1] = true;
            dist[x][y + 1] = dist[x][y] + 1;
            moves[x][y + 1] = 'R';
            q.push({x, y + 1});
        }
    
        if (x - 1 >= 0 && !visited[x - 1][y] && labyrinth[x - 1][y] != '#') {
            visited[x - 1][y] = true;
            dist[x - 1][y] = dist[x][y] + 1;
            moves[x - 1][y] = 'U';
            q.push({x - 1, y});
        }

        if (x + 1 < n && !visited[x + 1][y] && labyrinth[x + 1][y] != '#') {
            visited[x + 1][y] = true;
            dist[x + 1][y] = dist[x][y] + 1;
            moves[x + 1][y] = 'D';
            q.push({x + 1, y});
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";

        cout << dist[end.first][end.second] << "\n";

        string path = "";
        ll x = end.first;
        ll y = end.second;

        while(x != start.first || y != start.second) {
            char move = moves[x][y];
            path += move;
            
            if (move == 'L') {
                y = y + 1;
            } 
            else if (move == 'R') {
                y = y - 1;
            }
            else if (move == 'U') {
                x = x + 1;
            } 
            else if (move == 'D') {
                x = x - 1;
            }
        }

        for (ll i = dist[end.first][end.second] - 1; i >= 0; i--) {
            cout << path[i];
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