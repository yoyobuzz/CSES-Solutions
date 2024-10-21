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

int dfs0(int u, int p, vector<vi> &adj, vi &sz){
    int ans = 1;
    for(auto v:adj[u]){
        if(v!=p){
            ans += dfs0(v, u, adj, sz);
        }
    }
    return sz[u] = ans;
}

int dfs1(int u, int p, vector<vi> &adj, vi &in, vi &sz){
    int ans = 0;
    for(auto v:adj[u]){
        if(v!=p){
            ans += sz[v] + dfs1(v, u, adj, in, sz);
        }
    }
    return in[u] = ans;
}

void dfs2(int u, int p, vector<vi> &adj, vi &in, vi& sz, vi &out){
    for(auto v:adj[u]){
        if(v!=p){
            out[v] += out[u] + in[u] - sz[v] - in[v] + ((adj.size()-1) - sz[v]);
            dfs2(v, u, adj, in, sz, out);
        }
    }
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
    
    vi in(n+1), out(n+1), sz(n+1);
    out[1] = 0;
    dfs0(1, 0, adj, sz);
    dfs1(1, 0, adj, in, sz);
    dfs2(1, 0, adj, in, sz, out);

    // for(int i=1; i<=n; i++){
    //     cout<<sz[i]<<" ";
    // }
    // cout<<nl;
    // for(int i=1; i<=n; i++){
    //     cout<<out[i]<<" ";
    // }
    // cout<<nl;

    for(int i=1; i<=n; i++){
        cout<<in[i] + out[i]<<" ";
    }

    cout<<"\n";
    return 0;
}