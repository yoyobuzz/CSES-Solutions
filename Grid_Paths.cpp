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

signed main()
{
    fast_io
    
    int n;
    cin>>n;
    vector<vi> m(n, vi (n, 1));
    char c;
    for(auto& i:m){
        for(auto& j:i){
            cin>>c;
            if(c == '*')
                j = 0;
        }
    }
    vector<vi> dp(n, vi (n, 0));
    for(int i=0;  i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j] == 0) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
            else{
                if(i-1>=0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j-1>=0){
                    dp[i][j] += dp[i][j-1];
                }
            }
            dp[i][j] %= M;
        }
    }
    
    cout<<dp[n-1][n-1];

    
    //cout<<"\n";
    return 0;
}