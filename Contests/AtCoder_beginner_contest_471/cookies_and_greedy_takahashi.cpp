#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    ll N; cin >> N;

    vector<ll> cookies_positions;

    vector<ll> pos;
    vector<ll> neg;

    for (ll i = 0; i < N; i++) {
        ll cp; cin >> cp;
        cookies_positions.push_back(cp);
        if (cp >= 0) {
            pos.push_back(cp);
        }
        else {
            neg.push_back(cp);
        }
    }

    pos.push_back(INF);
    neg.push_back(-INF);

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<ll>());

    ll curr = 0;
    ll count = 0;
    ll dist = 0;
    ll i_pos = 0;
    ll i_neg = 0;

    while(count != N) {
        if (abs(curr - neg[i_neg]) <= abs(curr - pos[i_pos])) {
            dist += abs(curr - neg[i_neg]);
            curr = neg[i_neg];
            i_neg++;
            count++;
            //cout << curr << "\n";
        }
        else {
            dist += abs(curr - pos[i_pos]);
            curr = pos[i_pos];
            i_pos++;
            count++;
            //cout << curr << "\n";
        }
    }

    cout << dist << "\n";
}

int main() {
    solve();
    return 0;
}
