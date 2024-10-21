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

vector<int> dp;
const int MOD = 1e9 + 7;

int solve(int sum){
    if(sum==0)
        return 1;
    if(dp[sum]!=-1)
        return dp[sum]%MOD;
    int ans = 0;
    for(int i=1; i<=6; i++){
        if(i<=sum){
            ans = (ans%MOD + solve(sum-i)%MOD)%MOD;
        }
    }
    return dp[sum] = ans%MOD;
}

signed main()
{
    fast_io
    
    int sum;
    cin>>sum;
    dp.resize(sum+1, -1);
    cout<<solve(sum)%MOD<<nl;
    //cout<<"\n";
    return 0;
}