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
    vector<vi> adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    set<pair<int, int>> st;
    vi dis(n, 1e9), par(n);
    st.insert({0, 0});
    dis[0] = 0;
    par[0] = -1;
    while(!st.empty()){
        auto [d, node] = *st.begin();
        st.erase(st.begin());
        for(auto v:adj[node]){
            if(d+1<dis[v]){
                par[v] = node;
                st.erase({dis[v], v});
                dis[v] = d+1;
                st.insert({d+1, v});
            }
        }
    }
    if(dis[n-1]==1e9){
        cout<< "IMPOSSIBLE" <<nl;
        return 0;
    }
    cout<<dis[n-1]+1<<nl;
    vi ans;
    int i = n-1;
    while(i!=-1){
        ans.push_back(i);
        i = par[i];
    }
    reverse(ans.begin(), ans.end());
    for(auto i:ans){
        cout<<i+1<<" ";
    }
    cout<<nl;
    
    //cout<<"\n";
    return 0;
}