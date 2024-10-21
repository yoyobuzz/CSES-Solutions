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

int dp[5001][5001];

int solve(string& s, string& t, int i, int j){
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i-1]==t[j-1]){
        return dp[i][j] = solve(s, t, i-1, j-1);
    }else{
        return dp[i][j] = 1 + min({solve(s, t, i, j-1), solve(s, t, i-1, j), solve(s, t, i-1, j-1)});
    }
}

signed main()
{
    fast_io
    
    memset(dp, -1, sizeof dp);
    string s, t;
    cin>>s>>t;
    int temp = solve(s, t, s.size(), t.size());
    cout<<temp<<nl;
    
    //cout<<"\n";
    return 0;
}