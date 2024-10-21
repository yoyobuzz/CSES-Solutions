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

signed main()
{
    fast_io
    
    int n, m, q;
    cin>>n>>m>>q;

    // vector<vector<pair<int, int>>> adj(n);


    vector<vi> dist(n, vi (n, 1e18));
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);

        // dist[v][u] = w;
        // dist[u][v] = w;

        // adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] < 1e18 &&  dist[k][j] < 1e18){
                    dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    for(int i=0; i<q; i++){
        int u, v;
        cin>>u>>v;
        int d = dist[--u][--v];
        if(d==1e18)
            cout<<-1<<nl;
        else cout<<d<<nl;
    }
    
    //cout<<"\n";
    return 0;
}