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
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    set<pair<int, int>> st;
    vi dis(n, 1e18);
    st.insert({0, 0});
    dis[0] = 0;
    while(!st.empty()){
        auto [d, u] = *st.begin();
        st.erase(st.begin());

        for(auto x:adj[u]){
            auto [v, w] = x;
            if(dis[v]>d+w){
                st.erase({dis[v], v});
                dis[v] = d+w;
                st.insert({d+w, v});
            }
        }

    }
    for(auto i:dis){
        cout<<i<<" ";
    }
    cout<<nl;
    //cout<<"\n";
    return 0;
}