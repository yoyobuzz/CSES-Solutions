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
int mod_exp(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
const int INV_2 = mod_exp(2, M-2, M);


int dp [501][125251];
int solve(int i, int t){
    if(t==0)
        return 1;
    if(i<=0)
        return 0;
    if(dp[i][t]!=-1)
        return dp[i][t];
    if(i<=t)
        return dp[i][t] = (solve(i-1, t-i) + solve(i-1, t)) % M;
    else
        return dp[i][t] = solve(i-1, t) % M;
}

signed main()
{
    fast_io
    
    int n;
    cin>>n;
    memset(dp, -1, sizeof dp);
    int target = (n*(n+1)/2); 
    if(target & 1)
        cout<<0<<nl;
    else{
        cout << (solve(n, target/2) * INV_2) % M << nl;
        // cout<<(solve(n-1, target/2))<<nl;
    }
    
    
    //cout<<"\n";
    return 0;
}
