#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;

    bool isnine = false;

    if (A + B == 9) {
        isnine = true;
    }
    else if (A - B == 9) {
        isnine = true;
    }
    else if ((A * B) == 9) {
        isnine = true;
    }
    else if ((float(A) / B) == 9) {
        isnine = true;
    }

    if (isnine) {
        cout << "Nine" << "\n";
    }
    else {
        cout << "Nein" << "\n";
    }

    return 0;
}
