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

const int LOG = 20;

void binary_lifting(int u, vector<vi> &adj, vi &p, vector<vi> &up){
    up[u][0] = p[u];
    for(int i=1; i<=LOG; i++){
        if(up[u][i-1] != -1 ){
            up[u][i] = up[up[u][i-1]][i-1]; 
        }else{
            up[u][i] = -1; 
        }
    }

    for(auto v:adj[u]){
        if(v != p[u]){
            binary_lifting(v, adj, p, up);
        }
    }
}

int solve(int x, int k, vector<vi> &up){
    if(x == -1 || k == 0)
        return x;
   
    for(int i = 0; i<=LOG; i++){
        if(k & (1<<i)){
            return solve(up[x][i], k ^ (1<<i), up);
        }
    }


     
    // for(int i = LOG; i>=0; i--){
    //     if(k & (1<<i)){
    //         x = up[x][i];
    //         if(x == -1) return -1;
    //     }
    // }
    // return x;
}

signed main()
{
    fast_io
    
    int n, q;
    cin>>n>>q;
    vi p(n+1);
    p[1] = -1;
    vector<vi> adj(n+1);
    for(int i=2; i<=n; i++){
        cin>>p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    vector<vi> up(n+1, vi (LOG+1, 0));
    for(int i=0; i<=LOG; i++){
        up[1][i] = -1;
    }
    binary_lifting(1, adj, p, up);
    // cout<<"fine"<<nl;
    for(int i=0; i<q; i++){
        int x, k;
        cin>>x>>k;
        for(int i = LOG; i>=0; i--){
            if(k & (1<<i)){
                x = up[x][i];
                if(x == -1) {cout<< -1<<nl; break;}
            }
            if(i==0)
                cout<< x<<nl;
        }
        // cout<<solve(x, k, up)<<nl;
    }

    
    cout<<"\n";
    return 0;
}