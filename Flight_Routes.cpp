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
    
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    priority_queue<int> qk[n+1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    vi ans;
    while(ans.size()<k){
        auto [d, u] = q.top();
        q.pop();
        if(u == n) {
            ans.push_back(d);
            // continue;
        }
        for(auto [v, w]:adj[u]){
            int temp = d + w;
            if(qk[v].size() < k){
                qk[v].push(temp);
                q.push({temp, v});
            }else if(temp < qk[v].top()){
                qk[v].push(temp);
                qk[v].pop();
                q.push({temp, v});
            }
        }
    }
    for(auto i:ans) cout<<i<<" ";
    cout<<nl;
    
    //cout<<"\n";
    return 0;
}