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

    vector<vector<int>> adj(n);
    vi in_deg(n, 0);
    for (int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        in_deg[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i < n; i++){
        if(in_deg[i] == 0) q.push(i);
    }

    vi par(n, -1);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v:adj[u]){
            in_deg[v]--;
            if(in_deg[v] == 0 && v != 0){
                par[v] = u;
                q.push(v);
            }
        }
    }
    
    if(par[n-1] != -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    q.push(0);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v:adj[u]){
            in_deg[v]--;
            if(in_deg[v] == 0){
                par[v] = u;
                q.push(v);
            }
        }
    }

    if(par[n-1] == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vi ans;
    int u = n-1;
    while(u != -1){
        ans.push_back(u);
        u = par[u];
    }
    reverse(all(ans));
    cout<<ans.size()<<nl;
    for(auto i:ans){
        cout<<i + 1<<" ";
    }
    cout<<nl;

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

// signed main()
// {
//     fast_io
    
//     int n, m;
//     cin>>n>>m;

//     vector<vector<int>> adj(n);
//     vi in_deg(n, 0);
//     for (int i = 0; i < m; i++){
//         int u, v;
//         cin>>u>>v;
//         u--, v--;
//         in_deg[v]++;
//         adj[u].push_back(v);
//     }
//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {
//         if(in_deg[i] == 0) q.push(i);
//     }
//     vi topo;
//     while(!q.empty()){
//         auto u = q.front();
//         q.pop();
//         topo.push_back(u);
//         for(auto v:adj[u]){
//             if(in_deg[v]>0){
//                 in_deg[v]--;
//                 if(in_deg[v] == 0){
//                     q.push(v);
//                 }
//             }
//         }
//     }
    
//     vi dist(n, -1);
//     dist[0] = 0;
//     vi par(n, -1);
//     for(auto u:topo){
//         if(dist[u] != -1){
//             for(auto v:adj[u]){
//                 if(dist[v] < dist[u] + 1){
//                     dist[v] = dist[u] + 1;
//                     par[v] = u;
//                 }
//             }
//         }
//     }
//     if(dist[n-1] == -1){
//         cout<<"IMPOSSIBLE\n";
//         return 0;
//     }

//     vi ans;
//     int u = n-1;
//     while(u != -1){
//         ans.push_back(u);
//         u = par[u];
//     }
//     reverse(all(ans));
//     cout<<dist[n-1] + 1<<nl;
//     for(auto i:ans){
//         cout<<i + 1<<" ";
//     }
//     cout<<nl;

//     //cout<<"\n";
//     return 0;
// }