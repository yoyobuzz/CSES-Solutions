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

void dfs(int u, vector<vi> &adj, vi &vis){
    vis[u] = 1;
    for(auto v:adj[u]){
        if(!vis[v]) dfs(v, adj, vis); 
    }
}

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;

    vector<vi> adj(n), radj(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vi vis(n, 0);
    dfs(0, adj, vis);
    for(int i=1; i<n; i++){
        if(!vis[i]){
            cout<<"NO"<<nl;
            cout<<1<<" "<<i+1<<nl;
            return 0;
        }
    }
    vis.assign(n, 0);
    dfs(0, radj, vis);
    for(int i=1; i<n; i++){
        if(!vis[i]){
            cout<<"NO"<<nl;
            cout<<i+1<<" "<<1<<nl;
            return 0;
        }
    }
  

    cout<<"YES"<<nl;
    
    //cout<<"\n";
    return 0;
}