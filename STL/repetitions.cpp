#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;

    ll n = s.length();

    ll longest_repetition = 1;
    ll current_repetition = 1;

    for (ll i = 1; i < n; i++) {
        if (s[i-1] == s[i]) {
            current_repetition++;
        }
        else {
            current_repetition = 1;
        }

        if (current_repetition > longest_repetition) {
            longest_repetition = current_repetition;
        }
    }

    cout << longest_repetition << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}