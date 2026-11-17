#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool have_testcases = true;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll take_all = abs((a + c) - b);
    ll take_none = abs(a - b);

    ll res = max(take_all, take_none);

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (have_testcases) {
        ll t;
        cin >> t;
        while (t--) {
            solve();
        }
    }
    else {
        solve();
    }
    
    return 0;
}