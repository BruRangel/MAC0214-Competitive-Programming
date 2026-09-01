#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> weights;

    for (ll i = 0; i < n; i++) {
        ll p_i;
        cin >> p_i;
        weights.push_back(p_i);
    }

    sort(weights.begin(), weights.end());

    ll n_gondolas = 0;
    ll left_pointer = 0;
    ll right_pointer = n - 1;

    while(left_pointer <= right_pointer) {
        if (left_pointer == right_pointer) {
            n_gondolas++;
            break;
        }
        if (weights[right_pointer] + weights[left_pointer] <= x) {
            n_gondolas++;
            left_pointer++;
            right_pointer--;
        }
        else {
            n_gondolas++;
            right_pointer--;
        }
    }

    cout << n_gondolas << "\n";
}

int main() {
    solve();
    return 0;
}
