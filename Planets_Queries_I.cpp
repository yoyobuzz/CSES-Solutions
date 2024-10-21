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

const int MAX_N = 1e9+1;
int LOG = 30;

int n, q;
// vector<vi> up;
// vi p;
int up[200001][31];
int p[200001];

int solve(int u, int k){
    for(int i=LOG; i>=0; i--){
        if(k & (1<<i)){
            u = up[u][i];
        }
    }
    return u;
}


signed main()
{
    fast_io

    cin>>n>>q;

    // p = vi(n+1);
    // while(1<<(LOG+1) <= MAX_N) LOG++;
    // up = vector<vi> (n+1, vi (LOG+1));

    for(int i=1; i<=n; i++){
        cin>>p[i];
        up[i][0] = p[i];
    }
    
    for(int j=1; j<=LOG; j++){
        for(int i=1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }


    for(int i=0; i<q; i++){
        int u, k;
        cin>>u>>k;
        if(up[u][0] == u){
            cout<<u<<nl;
            continue;
        }
        cout<<solve(u, k)<<nl;
    }
    
    //cout<<"\n";
    return 0;
}