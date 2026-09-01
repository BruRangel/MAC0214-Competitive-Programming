#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll N; cin >> N;
    vector<string> strings;
    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c);});
        strings.push_back(s);
    }

    unordered_map<string, ll> count;

    for (ll i = 0; i < N; i++) {
        string s = strings[i];
        count[s]++;
    }

    ll max_repetitions = 0;
    for (ll i = 0; i < N; i++) {
        string s = strings[i];
        if (count[s] > max_repetitions) {
            max_repetitions = count[s];
        }
    }

    cout << max_repetitions << "\n";
}

int main() {
    solve();
    return 0;
}
