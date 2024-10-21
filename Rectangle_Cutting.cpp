#include <bits/stdc++.h>

using namespace std;

#define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define test int ttttt; cin>>ttttt; while(ttttt--) solve();
#define nl "\n"
typedef vector<int> vi;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define f(i, p, n) for(int i=p; i<n; i++)

int dp[501][501];

int solve(int n, int m){
    if(n==m)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(dp[m][n]!=-1)
        return dp[m][n];
    int ans = INT_MAX;
    for(int i=1; i<n; i++){
        ans = min(ans, 1 + solve(n-i, m) + solve(i, m));
    }
    for(int i=1; i<m; i++){
        ans = min(ans, 1 + solve(n, m-i) + solve(n, i));
    }
    return dp[n][m] = ans;
}

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout<<solve(m, n)<<nl;

    //cout<<"\n";
    return 0;
}