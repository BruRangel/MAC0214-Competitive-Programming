#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll MOD = 1000000007;
 
// Transforma a sequência:
// v[inicio], v[inicio + passo], v[inicio + 2 * passo], ...
void transforma(vector<ll>& v, int inicio, int passo, int tamanho) {
    if (tamanho % 2 == 1) {
        ll soma = 0;
 
        // Posições 1, 3, 5, ... correspondem aos índices 0, 2, 4, ...
        for (int k = 0; k < tamanho; k += 2) {
            soma = (soma + v[inicio + k * passo]) % MOD;
        }
 
        for (int k = 0; k < tamanho; ++k) {
            v[inicio + k * passo] = (k % 2 == 0 ? soma : 0);
        }
 
        return;
    }
 
    ll paresDireita = 0;
 
    // Soma inicial das posições 2, 4, 6, ...
    for (int k = 1; k < tamanho; k += 2) {
        paresDireita = (paresDireita + v[inicio + k * passo]) % MOD;
    }
 
    ll imparesEsquerda = 0;
 
    for (int k = 0; k < tamanho; ++k) {
        int pos = inicio + k * passo;
        ll x = v[pos];  // Guarda o valor antes de sobrescrevê-lo.
 
        if (k % 2 == 0) {
            // Posição ímpar na indexação começando em 1.
            imparesEsquerda = (imparesEsquerda + x) % MOD;
            v[pos] = (MOD - paresDireita) % MOD;
        } else {
            // Posição par na indexação começando em 1.
            paresDireita = (paresDireita - x + MOD) % MOD;
            v[pos] = (MOD - imparesEsquerda) % MOD;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<ll> a(n * m);
 
        for (ll& x : a) {
            cin >> x;
            x = (x % MOD + MOD) % MOD;
        }
 
        vector<ll> b = a;
 
        // Cada linha tem m elementos consecutivos.
        for (int i = 0; i < n; ++i) {
            transforma(b, i * m, 1, m);
        }
 
        // Cada coluna tem n elementos separados por m posições.
        for (int j = 0; j < m; ++j) {
            transforma(b, j, m, n);
        }
 
        ll resposta = 0;
 
        for (int k = 0; k < n * m; ++k) {
            resposta = (resposta + a[k] * b[k]) % MOD;
        }
 
        cout << resposta << '\n';
    }
}