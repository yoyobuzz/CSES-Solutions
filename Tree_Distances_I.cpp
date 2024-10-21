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

int dfs1(int u, int p, vector<vi> &adj, vi &in){
    int ans = 0;
    for(auto v:adj[u]){
        if(p!=v){
            ans = max(ans, 1+dfs1(v, u, adj, in));
        }
    }
    return in[u] = ans;
}

void dfs2(int u, int p, vector<vi> &adj, vi &in, vi &out){
    int mx1 = -1, mx2 = -1;
    for(auto v:adj[u]){
        if(p!=v){
            int temp = in[v];
            if(temp>=mx1){
                mx2 = mx1;
                mx1 = temp;
            }else if(temp>=mx2){
                mx2 = temp;
            }
        }
    }
    for(auto v:adj[u]){
        if(p!=v){
            if(in[v] == mx1){
                out[v] = max(1 + out[u], 2 + mx2);
            }else{
                out[v] = max(1 + out[u], 2 + mx1);
            }
            dfs2(v, u, adj, in, out);
        }
    }

}


signed main()
{
    fast_io
    
    int n;
    cin>>n;

    vector<vi> adj(n+1);
    vector<pair<int, int>>e;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e.push_back({u, v});
    }
    
    vi in(n+1), out(n+1);
    
    dfs1(1, 0, adj, in);
    
    out[1] = 0;
    dfs2(1, 0, adj, in, out);

    for(int i=1; i<=n; i++){
        cout<<max(in[i], out[i])<<" ";
    }

    //cout<<"\n";
    return 0;
}