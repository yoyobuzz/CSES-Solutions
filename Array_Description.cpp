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

int n, m;
int dp[100001][101];
const int M = 1e9 + 7;
int solve(int i, int prev, vi& a){
    if(i<0)
        return 1;
    if(dp[i][prev]!=-1)
        return dp[i][prev];
    if(a[i]!=0){
        if(abs(prev-a[i])>1)
            return dp[i][prev] = 0;
        else return dp[i][prev] = solve(i-1, a[i], a);
    }else{
        int ans = 0;
        for(int k=max(prev-1, 1LL); k<=min(prev+1, m); k++){
            ans += solve(i-1, k, a) % M;
            ans %= M;
        }
        return dp[i][prev] = ans;
    }
}


signed main()
{
    fast_io
    
    // int n, m;
    cin>>n>>m;
    vi a(n);
    for(auto &i:a) cin>>i;
    int ans = 0;

    // memset(dp, -1, sizeof(dp));

    for(int i=0; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==0) dp[i][j] = 1;
            else if(a[i-1]!=0){
                if(abs(j-a[i-1])>1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp [i-1][a[i-1]];
                }
            }else{
                int temp = 0;
                for(int k=max(j-1, 1LL); k<=min(j+1, m); k++){
                    temp += dp[i-1][k] % M;
                    temp %= M;
                }
                dp[i][j] = temp;
            }
        }
    }


    if(a[n-1]==0){
        for(int k=1; k<=m; k++){
            // memset(dp, -1, sizeof(dp));
            // ans += solve(n-2, k, a);
            
            ans += dp[n-1][k];
            ans %= M;
        }
    }else{
        // memset(dp, -1, sizeof(dp));
        // ans = solve(n-1, a[n-1], a);

        ans += dp[n][a[n-1]];
        ans %= M;
    }
    cout<<ans;

    
    //cout<<"\n";
    return 0;
}