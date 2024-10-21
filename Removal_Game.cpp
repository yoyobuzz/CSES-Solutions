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

int n;
int dp[5002][5002][2];
int solve(int i, int j, int t, vi& a){
    if(i>j)
        return 0;
    if(t){
        return max(a[i] + solve(i+1, j, 0, a), a[j] + solve(i, j-1, 0, a));
    }
    else{
        return min(solve(i+1, j, 1, a), solve(i, j-1, 1, a));
    }
}

signed main()
{
    fast_io
    
    // int n;
    cin>>n;
    vi a(n);
    for(auto &i:a) cin>>i;

    // cout<<solve(0, n-1, 1, a);
    memset(dp, 0, sizeof dp);
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, 0)));

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=n-1; j++){
            for(int t=0; t<=1; t++){
                if(i>j)
                    dp[i][j][t] = 0;
                else if(i==j)
                    dp[i][j][1] = a[i]; 
                else if (t)
                    dp[i][j][t] = max (a[i] + dp[i+1][j][0], a[j] + dp[i][j-1][0]);
                else
                    dp[i][j][t] = min (dp[i+1][j][1], dp[i][j-1][1]);
            }
        }
    }
    cout<<dp[0][n-1][1]<<nl;


    // cout<<"\n";
    return 0;
}