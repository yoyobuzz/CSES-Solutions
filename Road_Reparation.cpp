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
    vi p, size, rank;
public:
    DSU(int n){
        p.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);

        for(int i=0; i<n; i++){
            p[i] = i;
        }
    }

    int find(int v){
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    void union_size(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(size[u] < size[v]){
            p[u] = v;
            size[v] += size[u];
        }else{
            p[v] = u;
            size[u] += size[v];
        }
    }

    
    void union_rank(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v])
            p[u] = v;
        else if(rank[v] < rank[u])
            p[v] = u;
        else{
            p[u] = v;
            rank[v] ++;
        }
        // if(rank[u] <= rank[v]){
        //     p[u] = v;
        //     rank[v] += 1;
        // }else{
        //     p[v] = u;
        //     rank[u] += 1;
        // }
    }
};

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;

    // auto cmp = [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
    //     return a.first < b.first;
    // };

    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp) > pq(cmp); 

    vector<vector<int>> edges(m);

    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edges[i] = {w, u, v};
    }

    sort(edges.begin(), edges.end(), [](vi& a, vi& b){
        return a[0]<b[0];
    });

    DSU dsu = DSU(n);
    int cost = 0;

    for(int i=0; i<m; i++){
        if(dsu.find(edges[i][1]) != dsu.find(edges[i][2])){
            cost += edges[i][0];
            dsu.union_size(edges[i][1], edges[i][2]);
        }
    }

    for(int i=1; i<n; i++){
        if(dsu.find(i) != dsu.find(0)){
            cout<<"IMPOSSIBLE"<<nl;
            return 0;
        }
    }

    cout<<cost<<nl;

    //cout<<"\n";
    return 0;
}