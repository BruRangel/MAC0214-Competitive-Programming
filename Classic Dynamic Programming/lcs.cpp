#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    ll n = s.size();
    ll m = t.size();

    // dp[i][j] == comprimento da LCS de s[0, i-1] e t[0, j-1]
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // reconstrução da LCS
    string resposta = "";
    ll i = n;
    ll j = m;

    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            resposta.push_back(s[i - 1]);
            i--;
            j--;
        } 
        else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } 
        else {
            j--;
        }
    }

    reverse(resposta.begin(), resposta.end());

    cout << resposta << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}