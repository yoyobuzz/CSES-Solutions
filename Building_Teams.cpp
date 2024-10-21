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

vector<vi> adj;
vi vis, col;

void dfs(int u, int c){
    vis[u] = 1;
    col[u] = c;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v, !c);
        }
    }
}


signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    adj.resize(n);
    vis.resize(n, 0);
    col.resize(n, -1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(i, 0);
    }
    for(int i=0; i<n; i++){
        for(auto v:adj[i]){
            if(col[i]==col[v]){
                cout<<"IMPOSSIBLE"<<nl;
                return 0;
            }
        }
    }
    for(auto i:col){
        cout<<i+1<<" ";
    }
    cout<<nl;

    
    //cout<<"\n";
    return 0;
}