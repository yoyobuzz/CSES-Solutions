#include <bits/stdc++.h>

using namespace std;

#define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define nl "\n"
typedef vector<int> vi;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define f(i, p, n) for(int i=p; i<n; i++)

signed main()
{
    fast_io
    
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << nl;
        return 0;
    }
    
    vector<pair<int, pair<int, int>>> a(n);
    for(int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {v, {u, w}};
    }
    
    sort(all(a));
    vector<int> dp(n+1);
    dp[0] = a[0].second.second;

    for(int i = 1; i < n; i++) {
        auto [end, pp] = a[i];
        auto [start, pay] = pp;
        
        pair<int, pair<int, int>> temp = {start, {0, 0}};
        auto it = lower_bound(a.begin(), a.end(), temp);
        
        if (it == a.begin()) {
            dp[i] = max(dp[i-1], pay);
        } else {
            dp[i] = max(dp[i-1], dp[(--it - a.begin())] + pay);
        }
    }
    cout<< dp[n-1] <<nl;
    // cout << *max_element(all(dp)) << nl;
    
    return 0;
}
