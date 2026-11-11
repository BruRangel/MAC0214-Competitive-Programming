#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void generate_sums(ll i, ll current_sum, const vector<ll> &array, vector<ll> &sums) {
    if (i == array.size()) {
        sums.push_back(current_sum);
        return;
    }

    generate_sums(i + 1, current_sum, array, sums);
    generate_sums(i + 1, current_sum + array[i], array, sums);
}

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> numbers(n);
    for (ll i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    ll middle = n /2;
    vector<ll> esq(numbers.begin(), numbers.begin() + middle);
    vector<ll> dir(numbers.begin() + middle, numbers.end());

    vector<ll> sums_esq, sums_dir;

    generate_sums(0, 0, esq, sums_esq);
    generate_sums(0, 0, dir, sums_dir);

    sort(sums_dir.begin(), sums_dir.end());

    ll nways = 0;

    for (ll sum : sums_esq) {
        ll target = x - sum;

        // acha o primeiro elemento >= ao target
        auto linf = lower_bound(sums_dir.begin(), sums_dir.end(), target);
        // acha o primeiro elemento maior que o target
        auto lsup = upper_bound(sums_dir.begin(), sums_dir.end(), target);

        nways += (lsup - linf);
    }   

    cout << nways << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
