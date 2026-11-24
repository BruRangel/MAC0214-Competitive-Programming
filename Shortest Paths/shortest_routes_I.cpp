#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void solve() {
    ll num_cities, num_flights;
    cin >> num_cities >> num_flights;

    // Lista de adjacência: {destino, custo}
    vector<vector<pair<ll, ll>>> adj_list(num_cities + 1);
    for (ll i = 0; i < num_flights; i++) {
        ll origin, destination, cost;
        cin >> origin >> destination >> cost;
        adj_list[origin].push_back({destination, cost});
    }

    vector<ll> min_dist(num_cities + 1, INF);
    // Min-heap para processar sempre a menor distância primeiro: {distância, cidade}
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> priority_q;

    min_dist[1] = 0;
    priority_q.push({0, 1});

    while (!priority_q.empty()) {
        ll curr_dist = priority_q.top().first;
        ll curr_city = priority_q.top().second;
        priority_q.pop();

        // Ignora entradas desatualizadas que ficaram na fila
        if (curr_dist > min_dist[curr_city]) {
            continue;
        }

        // Relaxamento das arestas vizinhas
        for (auto flight : adj_list[curr_city]) {
            ll next_city = flight.first;
            ll flight_cost = flight.second;

            if (min_dist[curr_city] + flight_cost < min_dist[next_city]) {
                min_dist[next_city] = min_dist[curr_city] + flight_cost;
                priority_q.push({min_dist[next_city], next_city});
            }
        }
    }

    for (ll city = 1; city <= num_cities; city++) {
        cout << min_dist[city] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}