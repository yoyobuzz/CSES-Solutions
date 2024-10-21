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

// vector<vi> dp;
int dp[101][1000001];

int solve(int i, int sum, vi& a){
    if(sum<=0)
        return 0;
    if(i<=0)
        return INT_MAX;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(a[i-1]<=sum){
        return dp[i][sum] = min(1LL+(ll)solve(i, sum-a[i-1], a), (ll)solve(i-1, sum, a));
    }else{
        return dp[i][sum] = solve(i-1, sum, a);
    }
}

signed main()
{
    fast_io
    
    int n, sum;
    cin>>n>>sum;
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // sort(a.begin(), a.end());

    // memset(dp, -1, sizeof(dp));
    // int ans = solve(n, sum, a);
    
    
    // dp.resize(n+1, vi(sum+1, -1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) dp[i][j]=0;
            else if(i==0) dp[i][j]=INT_MAX-1;
            else if(a[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-a[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = dp[n][sum];

    if(ans==INT_MAX-1 || ans==INT_MAX)
        cout<<-1<<nl;
    else
        cout<<ans<<nl;
    
    //cout<<"\n";
    return 0;
}