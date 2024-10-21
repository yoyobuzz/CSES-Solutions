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

const int mod = 1e9 + 7;

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vi in(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!in[i]) q.push(i);
    }
    vi ways(n+1, 0);
    ways[1] = 1;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v:adj[u]){
            ways[v] += ways[u] % mod;
            ways[v] %= mod;
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    cout<<ways[n]<<nl;
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

// const int mod = 1e9 + 7;

// signed main()
// {
//     fast_io
    
//     int n, m;
//     cin>>n>>m;

//     vector<vi> adj(n);
//     vi indegree(n, 0);
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>>v;
//         u--, v--;
//         adj[u].push_back(v);
//         indegree[v]++;
//     }

//     vi ways(n, 0);
//     ways[0] = 1;
//     queue<int> q;

//     for(int i=0; i<n; i++){
//         if(indegree[i]==0)
//             q.push(i);
//     }

//     while(!q.empty()){
//         auto u = q.front();
//         q.pop();
//         for(auto v:adj[u]){
//             (ways[v] += ways[u]) %= mod;
//             indegree[v]--; 
//             if(indegree[v]==0)
//                 q.push(v);
//         }
//     }

//     cout<<ways[n-1];



//     //cout<<"\n";
//     return 0;
// }