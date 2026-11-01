#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> board(8);
int n_ways = 0;

// Verifica se podemos colocar a rainha em (r, c) olhando para as rainhas já processadas acima
bool safe(int r, int c) {
    // Verifica as colunas acima
    for (int i = r - 1; i >= 0; --i) {
        if (board[i][c] == 'Q') return false;
    }

    // Verifica as diagonais "\"
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Verifica as diagonais "/"
}

void backtrack() {

}

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
