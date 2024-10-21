#include <bits/stdc++.h>

using namespace std;

#define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
// #define int long long
#define test int ttttt; cin>>ttttt; while(ttttt--) solve();
#define nl "\n"
typedef vector<int> vi;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define f(i, p, n) for(int i=p; i<n; i++)

int dp[1001][100001];

int solve(int i, int t, vi& w, vi& a){
    if(i<=0 || t<=0)
        return 0;
    if(dp[i][t]!=-1)
        return dp[i][t];
    if(w[i-1]<=t){
        return dp[i][t] = max(a[i-1] + solve(i-1, t-w[i-1], w, a), solve(i-1, t, w, a));
    }else{
        return dp[i][t] = solve(i-1, t, w, a);
    }
}

signed main()
{
    fast_io
    
    int n, t;
    cin>>n>>t;
    vi a(n), w(n);
    for(int i=0; i<n; i++) cin>>w[i];
    for(int i=0; i<n; i++) cin>>a[i];
     
    // memset(dp, -1, sizeof(dp));
    // cout<<solve(n, t, w, a);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=t; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(w[i-1]<=j)
                dp[i][j] = max (a[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout<<dp[n][t];

    //cout<<"\n";
    return 0;
}