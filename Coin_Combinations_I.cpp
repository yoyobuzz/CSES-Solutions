#include <bits/stdc++.h>

using namespace std;

#define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
#define test int ttttt; cin>>ttttt; while(ttttt--) solve();
#define nl "\n"
typedef vector<int> vi;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define f(i, p, n) for(int i=p; i<n; i++)

const int MOD = (int)1e9 + 7;
ll dp[1000001];

signed main()
{
    fast_io
    
    int n, sum;
    cin >> n >> sum;
    vi a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // vector<ll> dp(sum+1, 0);
    
    dp[0] = 1;

    for(int i=0; i<=sum; i++){
        for(int j=0; j<n; j++){
            if(a[j]<=i)
                dp[i] += dp[i - a[j]];
            dp[i] %= MOD;
        }
    }
    int ans = dp[sum];
    cout << ans << nl;
    //cout<<"\n";
    return 0;
}