#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Ponto {
    ll x, y;
};

ll orientacao(Ponto a, Ponto b, Ponto c) {
    ll cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross > 0) {
        return 1;
    }
    if (cross < 0) {
        return -1;
    }
    return 0;
}

bool no_segmento(Ponto a, Ponto b, Ponto p) {
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

void solve() {
    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++) {
        Ponto p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

        ll o1 = orientacao(p1, p2, p3);
        ll o2 = orientacao(p1, p2, p4);
        ll o3 = orientacao(p3, p4, p1);
        ll o4 = orientacao(p3, p4, p2);

        // Segmentos se cruzam
        bool intersecta = (o1 != o2 && o3 != o4);

        // Pontos colineares ou vértices compartilhados
        if (o1 == 0 && no_segmento(p1, p2, p3)) {
            intersecta = true;
        } 
        if (o2 == 0 && no_segmento(p1, p2, p4)) {
            intersecta = true;
        }
        if (o3 == 0 && no_segmento(p3, p4, p1)) {
            intersecta = true;
        }
        if (o4 == 0 && no_segmento(p3, p4, p2)) {
            intersecta = true;
        }

        if (intersecta) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
