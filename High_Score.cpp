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

vi vis, cnt;
vector<vector<int>> adj, radj;

void dfs(int u){
    vis[u] = 1;
    cnt[u] += 1;
    for(auto v:adj[u]){
        if(!vis[v])
            dfs(v);
    }
}

void rdfs(int u){
    vis[u] = 1;
    cnt[u] += 1;
    for(auto v:radj[u]){
        if(!vis[v])
            rdfs(v);
    }
}


signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    vector<vi> edges(m);
    vector<vi> redges(m);
    adj.resize(n);
    radj.resize(n);

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edges[i] = {u, v, w};
        redges[i] = {u, v, w};
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vi dist(n, -1e18);
    dist[0] = 0;

    
    for(int i=0; i<n-1; i++){
        for(auto &e:edges){
            int u = e[0], v = e[1], w = e[2];
            if(dist[u] != -1e18 && dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    vis.assign(n, 0);
    cnt.assign(n, 0);
    dfs(0);
    vis.assign(n, 0);
    rdfs(n-1);
    for(auto &e:edges){
        int u = e[0], v = e[1], w = e[2];
        if(cnt[u]!=2) continue;
        if(dist[u] != -1e18 && dist[u] + w > dist[v]){
            cout<<-1<<nl;
            return 0;
        }
    }

    cout<<dist[n-1]<<nl;
    
    //cout<<"\n";
    return 0;
}