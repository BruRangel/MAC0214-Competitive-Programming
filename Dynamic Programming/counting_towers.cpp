#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 1e6;
const ll MODULE = 1e9 + 7;

// vector<vector<ll>> memo(MAX, vector<ll> (2));
// Talvez usar vector tenha esgotado a memória
ll memo[MAX][2];

void solve(ll n) {
    memo[0][0] = 1;
    memo[0][1] = 1;

    for (ll i = 1; i < n; i++) {
        memo[i][0] = (4 * memo[i - 1][0] + memo[i - 1][1]) % MODULE;
        memo[i][1] = (memo[i - 1][0] + 2 * memo[i - 1][1]) % MODULE;
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
        cout << (memo[n - 1][0] + memo[n - 1][1]) % MODULE << "\n";
    }

    return 0;
}
