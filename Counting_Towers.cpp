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

const int M = 1e9 + 7;
int dp[1000001][2];

int solve(int n, int last){
    if(n==1)
        return dp[n][last] = 1;

    if(dp[n][last] != -1)
        return dp[n][last];

    dp[n][0] = (4 * solve(n-1, 0) % M + 1 * solve(n-1, 1) % M) % M; 
    dp[n][1] = (1 * solve(n-1, 0) % M + 2 * solve(n-1, 1) % M) % M; 

    return dp[n][last] % M;
}

//0 -> [][]
//1 -> [  ]

signed main()
{
    fast_io
    
    // solve(1000000, 0);
    memset(dp, -1, sizeof dp);
    int ttt;
    cin>>ttt;
    while(ttt--){
        int n;
        cin>>n;
    
        if(dp[n][0]==-1)
            solve(n, 0);
        
        if(dp[n][1]==-1)
            solve(n, 1);

        cout<<(dp[n][0]+dp[n][1])% M<<nl;   
    
    }
    
    //cout<<"\n";
    return 0;
}