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

int n;
vector<vi> adj, up;
vi p, lvl;
const int LOG = 20;

void dfs(int u){
    for(auto v: adj[u]){
        if(v == p[u]) continue;
        lvl[v] = lvl[u] + 1;
        up[v][0] = u;
        for(int i=1; i<=LOG; i++){
            if(up[v][i-1] != -1){
                up[v][i] = up[up[v][i-1]][i-1];
            }
        }
        dfs(v);
    }
}

int lca(int u, int v){
    if(lvl[u] < lvl[v])
        swap(u, v);

    int k = lvl[u] - lvl[v];
    for(int i=0; i<=LOG; i++){
        if(k & (1<<i)){
            u = up[u][i];
        }
    }
    if(u == v)
        return u;
    for(int i=LOG; i>=0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}



signed main()
{
    fast_io
    
    int q;
    cin>>n>>q;

    adj = vector<vi> (n + 1);
    p = vi (n + 1);
    lvl = vi (n + 1);
    up = vector<vi> (n + 1, vi (LOG + 1));

    for(int i=2; i<=n; i++){
        cin>>p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    p[1] = -1;
    for(int i=0; i<=LOG; i++){
        up[1][i] = -1;
    }
    dfs(1);
    for(int i=0; i<q; i++){
        int u, v;
        cin>>u>>v;
        cout<<lca(u, v)<<nl;
    }
    //cout<<"\n";
    return 0;
}