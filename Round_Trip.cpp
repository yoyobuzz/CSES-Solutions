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

vi ans;
int dfs(int u, vector<vi> &adj, vi &vis, vi &par){
    vis[u] = 1;
    for(auto v:adj[u]){
        if(v == par[u]) continue;
        if(!vis[v]){
            par[v] = u;
            if(dfs(v, adj, vis, par)) return 1;
        }else{
            ans.push_back(v);
            int x = u;
            while(x != v){
                ans.push_back(x);
                x = par[x];
            }
            ans.push_back(v);
            return 1;
        }
    }
    return 0;
}

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    vector<vi> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n+1, 0), par(n+1, -1);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, par)) break;;
        }
    }


    if(ans.size() == 0){
        cout<<"IMPOSSIBLE"<<nl;
        return 0;
    }
    reverse(all(ans));
    cout<<ans.size()<<nl;
    for(auto i:ans){
        cout<<i<<" ";
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

// vector<vi> adj;
// vi vis, par;
// vi ans;

// int dfs(int u, int p){
//     vis[u] = 1;
//     par[u] = p;
//     for(auto v:adj[u]){
//         if(v==p) continue;
//         if(!vis[v]){
//             if(dfs(v, u)) return 1;
//         }
//         else{
//             ans.push_back(v);
//             while(u!=v && u!=-1){
//                 ans.push_back(u);
//                 u = par[u];
//             }
//             ans.push_back(v);
//             return 1;
//         }
//     } 
//     return 0;
// }

// signed main()
// {
//     fast_io
    
//     int n, m;
//     cin>>n>>m;
//     adj.resize(n);
//     vis.resize(n, 0);
//     par.resize(n, -1);
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>>v;
//         u--; v--;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     for(int i=0; i<n; i++){
//         if(!vis[i]){
//             if(dfs(i, -1)){
//                 cout<<ans.size()<<nl;
//                 for(auto x:ans){
//                     cout<<x+1<<" ";
//                 }
//                 cout<<nl;
//                 return 0;
//             }
//         }
//     }
//     cout<<"IMPOSSIBLE"<<nl;

//     // queue<pair<int, int>> q;
//     // for(int i=0; i<n; i++){
//     //     if(vis[i]) continue;

//     //     q.push({0, i});
//     //     vis[i] = 1;
//     //     dis[i] = 0;
//     //     while(!q.empty()){
//     //         auto [d, node] = q.front();
//     //         q.pop();
//     //         for(auto v:adj[node]){
//     //             if(!vis[v]){
//     //                 dis[v] = d+1;
//     //                 vis[v] = 1;
//     //                 q.push({d+1, v});
//     //             }else if(v != par[v] && dis[v]+d>2){
//     //                 cout<<dis[v]+d+1<<nl;
//     //                 vi ans;
//     //                 int k = v;
//     //                 while(k!=i){

//     //                 }
//     //             }
//     //         }
//     //     }
//     // }

    
//     //cout<<"\n";
//     return 0;
// }
