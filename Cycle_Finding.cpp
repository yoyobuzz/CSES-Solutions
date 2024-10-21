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



signed main(){
    fast_io
    
    int n, m;
    cin>>n>>m;

    vector<vi> edges(m);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edges[i] = {u, v, w};
    }

    vi dist(n, 1e18);
    dist[0] = 0;
    vi p(n, -1);

    for(int i=0; i<n-1; i++){
        for(auto &e:edges){
            int u = e[0], v = e[1], w = e[2];
            if(dist[u] + w < dist[v]){
                dist[v] = (dist[u] + w);
                p[v] = u;
            }
        }
    }
    for(auto &e:edges){
        int u = e[0], v = e[1], w = e[2];
        // cout<<u<<" "<<v<<nl;
        if(dist[u] + w < dist[v]){
            cout<<"YES"<<nl;
            // cout<<u<<" "<<v<<nl;
            p[v] = u;
            for(int i=0; i<n; i++){
                v=p[v];
            }
            vi ans;
            u = v;
            while(u!=v || ans.empty()){
                ans.push_back(u);
                u = p[u];
            }
            ans.push_back(v);
            reverse(ans.begin(), ans.end());
            for(auto i:ans){
                cout<<i+1<<" ";
            }
            cout<<nl;
            return 0;
        }
    }
    cout<<"NO"<<nl;
    //cout<<"\n";
    return 0;
}