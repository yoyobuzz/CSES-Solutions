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
 
int solve(int u, int p, int &ans, vector<vi> &adj, vi &dp){
    // if(dp[u] != -1) return dp[u];
    int mx = 0, se = 0;
    for(auto v:adj[u]){
        if(v==p) continue;
        int len = solve(v, u, ans, adj, dp);
        if(mx==0){
            mx = max(len, mx);
        }else if(len>=mx){
            se = mx;
            mx = len;
        }else if(len>=se){
            se = len;
        }
    }
    ans = max(ans, mx + se);
    return dp[u] = mx + 1;
}   
 
 
signed main()
{
    fast_io
    
    int n;
    cin>>n;
    
    vector<vi> adj(n+1);
 
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vi dp(n+1, -1);
    int ans = 0;
    solve(1, -1, ans, adj, dp);
    cout<<ans<<nl;
 
    //cout<<"\n";
    return 0;
}