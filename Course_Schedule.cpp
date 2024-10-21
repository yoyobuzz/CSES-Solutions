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
    vi indegree(n, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    
    vi ans;

    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        // indegree[u]--;
        q.pop();
        for(auto i:adj[u]){
            indegree[i]--;
            if(indegree[i]==0)
                q.push(i);
        }
    }
    
    if(ans.size()==n){
        for(auto i:ans){
            cout<<i+1<<" ";
        }
        cout<<nl;
    }else{
        cout<<"IMPOSSIBLE"<<nl;
    }
    
    
    //cout<<"\n";
    return 0;
}