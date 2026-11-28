#include <bits/stdc++.h>
    
typedef long long ll;
    
using namespace std;
    
const ll BIG = 1e9 + 7;
    
void run()
{
    ll n, k;
    cin >> n >> k;
    
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];
    
    const ll W = n - k + 1;
    ll answer = 0;
    
    ll i = 0;
    
    while (i < n)
    {
        ll j = i;
    
        while (j < n && vec[j] == vec[i])
            j++;
    
        ll L = j - i;
    
        if (L >= W)
            answer += L - W + 1;
    
        i = j;
    }
    
    cout << answer << "\n";
}
    
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll t;
    cin >> t;
    
    while (t--)
        run();
}
