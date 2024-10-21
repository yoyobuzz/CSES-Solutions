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

class DSU{

private:
    vi par, size;
public:
    DSU(int n){
        par.resize(n, 0);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }

    int find(int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    void union_size(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(size[a] <= size[b]){
            par[a] = b;
            size[b] += size[a];
        }else{
            par[b] = a;
            size[a] += size[b];    
        }
    }
    
};

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    DSU d(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        d.union_size(u, v);
    }
    int comp = 0;
    vector<pair<int, int>> ans;
    for(int i=1; i<n; i++){
        if(d.find(i) != d.find(i-1)){
            comp++;
            // bec i+1 is to be printed
            ans.push_back({i, i+1});
            d.union_size(i, i-1);
        }
    }
    cout<<comp<<nl;
    for(auto [u, v]:ans){
        cout<<u<<" "<<v<<nl;
    }
    
    //cout<<"\n";
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// #define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
// #define int long long
// #define test int ttttt; cin>>ttttt; while(ttttt--) solve();
// #define nl "\n"
// typedef vector<int> vi;
// typedef long long ll;
// #define all(a) (a).begin(), (a).end()
// #define f(i, p, n) for(int i=p; i<n; i++)

// vi vis;
// vector<vi> adj;

// void dfs(int u){
//     vis[u] = 1;
//     for(auto v:adj[u]){
//         if(!vis[v])
//             dfs(v);
//     }
// }


// signed main()
// {
//     fast_io
    
//     int n, m;
//     cin>>n>>m;
//     adj.resize(n);
//     vis.resize(n);
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>>v;
//         u--, v--;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int comp = 0;
//     vector<pair<int, int>> ans;
//     for(int i=0; i<n; i++){
//         if(!vis[i]){
//             if(comp>0){
//                 ans.push_back({i, i+1});
//             }
//             comp++;
//             dfs(i);
//         }
//     }
//     cout<<ans.size()<<nl;
//     for(auto i:ans){
//         cout<<i.first<<" "<<i.second<<nl;
//     }
//     cout<<nl;
//     //cout<<"\n";
//     return 0;
// }