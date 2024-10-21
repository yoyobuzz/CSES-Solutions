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

int mat[1000][1000];

signed main()
{
    fast_io
    
    int n, m;
    cin>>n>>m;
    // vector<vi> mat(n, vector<int> (m, 0));
    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>c;
            if(c=='.')
                mat[i][j] = 1;
            else 
                mat[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    int ans = 0;
    int x, y, a, b;
    int del[] = {-1, 0, 1, 0, -1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==1){
                ans++;
                q.push({i, j});
                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();
                    for(int i=0; i<4; i++){
                        a = x + del[i], b = y + del[i+1];
                        if(a>=0 && a<n && b>=0 && b<m && mat[a][b]==1){
                            mat[a][b] = 0;
                            q.push({a, b});
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<nl;
    
    //cout<<"\n";
    return 0;
}