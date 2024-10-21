#include <bits/stdc++.h>

using namespace std;

#define fast_io std::ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define test int ttttt; cin>>ttttt; while(ttttt--) solve();
#define nl "\n"
typedef vector<int> vi;
typedef long long ll;
#define all(a) (a).begin(), (a).fin()
#define f(i, p, n) for(int i=p; i<n; i++)

vector<vi> vis, mat;
vector<int> del;
int n, m;
string ans;
pair<int, int> start, fin;
vector<char> dell;

signed main()
{
    fast_io
    
    cin>>n>>m;
    mat.assign(n, vector<int> (m, 0));
    vis.assign(n, vector<int> (m, 0));
    del.assign({-1, 0, 1, 0, -1});
    dell.assign({'U', 'R', 'D', 'L'});

    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>c;
            if(c=='.' || c=='A' || c=='B')
                mat[i][j] = 1;
            else 
                mat[i][j] = 0;
            if (c=='A')
                start = {i, j};
            
            if (c=='B')
                fin = {i, j};
        }
    }
    
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>> (m));
    q.push({start.first, start.second});
    vis[start.first][start.second] = 1;
    bool found = false;
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if(i==fin.first && j==fin.second){
            found = 1;
            break;
        }
        for(int k=0; k<4; k++){
            int x = i + del[k], y = j + del[k+1];
            if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1 && !vis[x][y]){
                vis[x][y] = 1;
                par[x][y] = {i, j};
                q.push({x, y});
            }
        }
    }
    
    if(!found){
        cout<<"NO"<<nl;
        return 0;
    }
    
    int i=fin.first, j=fin.second;
    while(1){
        auto [pi, pj] = par[i][j];
        if(pi>i)
            ans.push_back('U');
        else if(pi<i)
            ans.push_back('D');
        else if(pj>j)
            ans.push_back('L');
        else if(pj<j)
            ans.push_back('R');
        i = pi;
        j = pj;
        
        if(i==start.first && j==start.second){
            break;
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout<<"YES"<<nl;
    cout<<ans.size()<<nl;
    cout<<ans<<nl;
    //cout<<"\n";
    return 0;
}