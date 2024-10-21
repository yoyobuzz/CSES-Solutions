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
 
// vector<vi> dp;
ll dp[2][1000001];
const int M = 1e9 + 7;
 
int solve(int i, int sum, vi& a){
    if(sum==0)
        return 1;
    if(i<=0)
        return 0;
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(a[i-1]<=sum)
        return dp[i][sum] = (solve(i, sum-a[i-1], a) % M + solve(i-1, sum, a) % M) % M;
    else
        return dp[i][sum] = solve(i-1, sum, a) % M; 
}
 
signed main()
{
    fast_io
    
    int n, sum;
    cin>>n>>sum;
    vi a(n);
    for(auto &i:a)
        cin>>i;
    
    // dp.resize(n+1, vi (sum+1, 0));
    // cout<<solve(n, sum, a)<<nl;
 
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0)
                dp[i%2][j] = 1;
            else if(i==0)
                dp[i%2][j] = 0;
            else if(a[i-1]<=j)
                dp[i%2][j] = (dp[i%2][j-a[i-1]] + dp[(i+1)%2][j]) % M;
            else
                dp[i%2][j] = dp[(i+1)%2][j] % M;
        }
    }
    
    cout<<dp[n%2][sum]<<nl;
 
    // cout<<"\n";
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// #define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
// #define int long long
// #define test int ttttt; cin>>ttttt; while(ttttt--) solve();
// #define nl "\n"
// typedef vector<int> vi;
// typedef long long ll;
// #define all(a) (a).begin(), (a).end()
// #define f(i, p, n) for(int i=p; i<n; i++)

// // vector<vi> dp;
// ll dp[1000001];

// const int M = (int)1e9 + 7;

// // int solve(int i, int sum, vi& a){
// //     if(sum==0)
// //         return 1;
// //     if(i<=0)
// //         return 0;
// //     if(dp[i][sum]!=-1)
// //         return dp[i][sum];
// //     if(a[i-1]<=sum)
// //         return dp[i][sum] = (solve(i, sum-a[i-1], a) % M + solve(i-1, sum, a) % M) % M;
// //     else
// //         return dp[i][sum] = solve(i-1, sum, a) % M; 
// // }

// signed main()
// {
//     fast_io
    
//     int n, sum;
//     cin>>n>>sum;
//     vi a(n);
//     for(auto &i:a)
//         cin>>i;
    
//     // dp.resize(n+1, vi (sum+1, 0));
//     // cout<<solve(n, sum, a)<<nl;
//     // vector<vi> dp(n+1, vi(sum+1, 0));
//     dp[0] = 1;

//     for(int i=1; i<=sum; i++){
//         for(int j=0; j<n; j++){
//             if(a[j]<=i)
//                 dp[i] = (dp[i-a[j]] + dp[i]) % M;;
//         }
//     }
    
//     cout<<dp[sum]<<nl;

//     // cout<<"\n";
//     return 0;
// }