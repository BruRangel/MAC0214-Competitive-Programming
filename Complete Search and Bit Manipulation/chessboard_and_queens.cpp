#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> board(8);
int n_ways = 0;

// verifica se podemos colocar a rainha em (r, c) olhando para as rainhas já processadas acima
bool safe(int r, int c) {
    // Verifica as colunas acima
    for (int i = r - 1; i >= 0; --i) {
        if (board[i][c] == 'Q') return false;
    }

    // verifica as diagonais "\"
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // verifica as diagonais "/"
    for (int i = r - 1, j = c + 1; i >= 0 && j < 8; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// r é a linha atual que estamos tentando inserir a rainha
void backtrack(int r) {
    if (r == 8) {
        n_ways++; // achamos uma solução
        return;
    }

    // backtracking: tenta colocar a rainha em cada coluna da linha r
    for (int c = 0; c < 8; c++) {
        if (board[r][c] == '.' && safe(r, c)) {
            board[r][c] = 'Q'; // insere a rainha
            backtrack(r + 1);   // avança para a próxima linha
            board[r][c] = '.';  // desfaz a inserção
        }
    }
}

void solve() {
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    backtrack(0);
    cout << n_ways << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
