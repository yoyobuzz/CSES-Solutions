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
 
int solve(int u, int p, int take, vector<vi> &adj, vector<vi> &dp){
    if(dp[u][take]!=-1)
        return dp[u][take];
    if(take){
        int temp = 0;
        for(auto v:adj[u]){
            if(p==v) continue;
            temp += solve(v, u, 1, adj, dp);
        }
        dp[u][take] = max(dp[u][take], temp);        
        for(auto v:adj[u]){
            if(p==v) continue;
            dp[u][take] = max(dp[u][take], temp -  solve(v, u, 1, adj, dp) + 1 + solve(v, u, 0, adj, dp));
        }
        
    }else{
        dp[u][take] = 0;
        for(auto v:adj[u]){
            if(p==v) continue;
            dp[u][take] += solve(v, u, 1, adj, dp);
        }
    }
    return dp[u][take];
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
 
    vector<vi> dp(n+1, vi (2, -1));
 
    cout<<solve(1, 1, 1, adj, dp)<<nl;
 
 
    //cout<<"\n";
    return 0;
}