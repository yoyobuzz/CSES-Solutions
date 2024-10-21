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


// int dp [200001][200001];

// int solve(int i, int j, vi& a){
//     if(i==0)
//         return 0;
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     if(j == -1)
//         return dp[i][j] = max (solve(i-1, j, a), 1 + solve(i-1, i-1, a));
//     if(a[i-1]<=a[j])
//         return dp[i][j] = max (solve(i-1, j, a), 1 + solve(i-1, i-1, a));
//     else
//         return dp[i][j] = solve(i-1, j, a);

// }



signed main()
{
    fast_io
    
    int n;
    cin>>n;
    vi a(n);
    for(auto &i:a) cin>>i;
    
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || ans.back()<a[i]){
            ans.push_back(a[i]);
        }else{
            ans [lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin()] = a[i];
        }
    }
    cout<<ans.size();
    
    // int dp[2][200001];

    // for(int i=0; i<=n; i++){
    //     for(int j=n; j>=0; j--){
    //         if(i==0)
    //             dp[i%2][j] = 0;
    //         else if(j == n)
    //             dp[i%2][j] = max (dp[(i-1)%2][j], 1 + dp[(i-1)%2][i-1]);
    //         else if(a[i-1]<a[j])
    //             dp[i%2][j] = max (dp[(i-1)%2][j], 1 + dp[(i-1)%2][i-1]);
    //         else
    //             dp[i%2][j] = dp[(i-1)%2][j];
    //     }
    // }

    // cout<<dp[n%2][n]<<nl;
    // memset(dp, -1, sizeof dp);
    // cout<<solve(n, -1, a)<<nl;
    
    //cout<<"\n";
    return 0;
}