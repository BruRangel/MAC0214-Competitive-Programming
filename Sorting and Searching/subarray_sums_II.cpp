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

    vector<ll> acm_numbers;
    acm_numbers[0] = numbers[0];
    for (ll i = 1; i < n; i++) {
        acm_numbers[i] = numbers[i] + acm_numbers[i-1];
    }

    
}

int main() {
    solve();
    return 0;
}