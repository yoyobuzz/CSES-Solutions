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
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vi dist(n + 1, 1e18);
    dist[1] = 0;
    pq.push({0, 1});
    
    #if ONLINE_JUDGE
        cout<<"hello"<<nl;
    #endif

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;  // Ignore outdated pairs

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    set<pair<int, int>> st;
    st.insert({0, 1});
    vi count(n+1, 0);
    count[1] = 1;
    while(!st.empty()){
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for(auto [v, w]:adj[u]){
            if(dist[v] == d + w){
                count[v] += count[u];
                count[v] %= mod;
                st.insert({dist[v], v});
            }
            
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq_steps;
    vi mn(n + 1, 1e18), mx(n + 1, 0);
    
    pq_steps.push({0, {0, 1}});  // {dist, {steps, node}}

    while (!pq_steps.empty()) {
        auto [d, temp] = pq_steps.top();
        auto [steps, u] = temp;
        pq_steps.pop();

        if (d > dist[u]) continue;  // Ignore outdated pairs

        for (auto [v, w] : adj[u]) {
            if (dist[v] == d + w) {
                mn[v] = min(mn[v], steps + 1);
                mx[v] = max(mx[v], steps + 1);
                pq_steps.push({dist[v], {steps + 1, v}});
            }
        }
    }

    cout<<dist[n]<<" "<<count[n]<<" "<<mn[n]<<" "<<mx[n]<<nl;

    
    //cout<<"\n";
    return 0;
}