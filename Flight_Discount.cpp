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

    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    vector<vector<pair<int, int>>> adj(n), radj(n);

    for (int i = 0; i < m; i++)    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edges[i] = {u, v, w};
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }

    vi dist0(n, 1e18), distn(n, 1e18);
    dist0[0] = 0;
    distn[n-1] = 0;
    set<pair<int, int>> st;
    st.insert({0, 0});
    while(!st.empty()){
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for(auto [v, dd]:adj[u]){
            if(dist0[v]>dd+d){
                st.erase({dist0[v], v});
                dist0[v] = dd + d;
                st.insert({dist0[v], v});
            }
        }
    }
    st.insert({0, n-1});
    while(!st.empty()){
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for(auto [v, dd]:radj[u]){
            if(distn[v]>dd+d){
                st.erase({distn[v], v});
                distn[v] = dd + d;
                st.insert({distn[v], v});
            }
        }
    }
    int ans = 1e18;
    for(int i=0; i<m; i++){
        int u = edges[i][0], v = edges[i][1], w =edges[i][2]; 
        ans = min(ans, dist0[u]+ w/2 + distn[v]);
    }
    cout<<ans<<nl;
    
    
    
    
    //cout<<"\n";
    return 0;
}