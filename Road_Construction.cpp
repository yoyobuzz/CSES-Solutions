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
    int mx;
    DSU(int n){
        par.resize(n, 0);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
        mx = 1;
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
        mx = max({mx, size[a], size[b]});
    }
    
};


signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;

    DSU dsu = DSU(n);
    int count = n;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(dsu.find(u) == dsu.find(v)){
            cout<<count<<" "<<dsu.mx<<nl;
        }else{
            dsu.union_size(u, v);
            count--;
            cout<<count<<" "<<dsu.mx<<nl;
        }
    }
    
    //cout<<"\n";
    return 0;
}