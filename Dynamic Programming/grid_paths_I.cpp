#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MODULE = 1e9 + 7;

ll n_paths(vector<vector<char>> &grid, ll n, ll current_x, ll current_y, vector<vector<ll>> &visited) {
    if ((current_x >= n) || (current_y >= n)) {
        return 0;
    }
    if ((current_x < 0) || (current_y < 0)) {
        return 0;
    }
    if (visited[current_x][current_y] != -1) {
        return visited[current_x][current_y];
    }
    if (grid[current_x][current_y] == '*') {
        return 0;
    }
    if ((current_x == n-1) && (current_y == n-1)) {
        return 1;
    }
    else {
        return visited[current_x][current_y] = 
        (n_paths(grid, n, current_x + 1, current_y, visited) +
        n_paths(grid, n, current_x, current_y + 1, visited)) % MODULE;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> visited(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            visited[i][j] = -1;
        }
    }

    cout << n_paths(grid, n, 0, 0, visited);

    return 0;
}
