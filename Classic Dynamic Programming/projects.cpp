#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Project {
    ll start;
    ll end;
    ll reward;
};

bool compare(const Project& a, const Project& b) {
    return a.end < b.end;
}

void solve() {
    ll n;
    cin >> n;

    vector<Project> projects(n);

    for (ll i = 0; i < n; i++) {
        ll start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = {start, end, reward};
    }

    sort(projects.begin(), projects.end(), compare);

    // Vetor só com os dias de término, já ordenado
    vector<ll> ends(n);
    for (ll i = 0; i < n; i++) {
        ends[i] = projects[i].end;
    }

    vector<ll> dp(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        ll skip = dp[i - 1];

        ll start_i = projects[i - 1].start;

        // pos = quantidade de projetos que terminam ANTES do início do projeto i
        ll pos = lower_bound(ends.begin(), ends.begin() + (i - 1), start_i) - ends.begin();

        ll take = projects[i - 1].reward + dp[pos];

        dp[i] = max(skip, take);
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}