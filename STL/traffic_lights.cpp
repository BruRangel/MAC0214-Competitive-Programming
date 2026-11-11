#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x, n;
    cin >> x >> n;

    set<ll> semaforos;
    multiset<ll> intervalos;

    semaforos.insert(0);
    semaforos.insert(x);
    intervalos.insert(x);

    for (ll i = 0; i < n; i++) {
        ll p;
        cin >> p;

        // semáforo à direita de p
        auto it = semaforos.lower_bound(p);

        // semáforo à esquerda de p
        auto it_esq = prev(it);

        ll dir = *it;
        ll esq = *it_esq;

        intervalos.erase(intervalos.find(dir - esq));
        intervalos.insert(p - esq);
        intervalos.insert(dir - p);

        semaforos.insert(p);

        cout << *intervalos.rbegin() << " ";
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