#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> numbers;

    for (ll i = 0; i < n; i++) {
        ll current;
        cin >> current;
        numbers.push_back(current);
    }

    // Seja $$P[i] = \sum_{j=0}^{i-1}\texttt{numbers[j]}$$

    // Temos que a soma do subarray numbers[l, r] é:
    // $$P[r+1] - P[l]$$
    // Queremos que $$P[r] - P[l-1] = x$$. Portanto $$ P[l-1] = P[r] - x $$.
    // Portanto, não armazenar cada prefix sum $$ P[r] $$.
    // Basta calcularmos quantas vezes $$P[r] - x $$ apareceu anteriormente
    // Podemos mapear essas frequências usando um unordered_map
    // Assim resolvemos com complexidade $$\mathcal{O}(n)$$.
    map<ll, ll> freq;
    freq[0] = 1;

    ll prefix = 0;
    ll res = 0;

    for (ll number : numbers) {
        prefix += number;
        res += freq[prefix - x];
        freq[prefix]++;
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
