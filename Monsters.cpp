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
    queue<pair<int, pair<int, int>>> q;
    pair<int, int> start;
    vector<vector<int>> mat(n, vi(m, 0));
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            char c;
            cin>>c;
            if(c == '#') mat[i][j] = 1;
            if(c == 'M') q.push({0, {i, j}});
            if(c == 'A') start = {i, j};
        }
    }

    vi del = {-1, 0, 1, 0, -1};
    vector<char> dir = {'U', 'R', 'D', 'L'};
    vector<vector<int>> par(n, vi(m, -1));

    vector<vi> safe(n, vi(m, 1e18)), vis(n, vi(m, 0));

    while(!q.empty()){
        auto [d, node] = q.front();
        auto [x, y] = node;
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        safe[x][y] = d;
        for(int k = 0; k<4; k++){
            int i = x + del[k], j = y + del[k+1];
            if(i>=0 && i<n && j>=0 && j<m && mat[i][j] == 0 && !vis[i][j]){
                q.push({d+1, {i, j}});
            }
        }
    }

    q.push({0, start});
    vis.assign(n, vi(m, 0));
    vis[start.first][start.second] = 1;
    while(!q.empty()){
        auto [d, node] = q.front();
        auto [x, y] = node;
        q.pop();

        if((x==0 || x==n-1) || (y==0 || y==m-1)){
            cout<<"YES"<<nl;
            cout<<d<<nl;
            string ans;
            int k = par[x][y];
            while (k != -1){
                ans.push_back(dir[k]);
                x -= del[k];
                y -= del[k+1];
                k = par[x][y];
            }
            reverse(ans.begin(), ans.end());
            cout<<ans<<nl;
            return 0;
        }
        for(int k = 0; k<4; k++){
            int i = x + del[k], j = y + del[k+1];
            if(i>=0 && i<n && j>=0 && j<m && mat[i][j] == 0 && !vis[i][j]){
                if(safe[i][j] > d + 1){
                    vis[i][j] = 1;
                    par[i][j] = k;
                    q.push({d+1, {i, j}});
                }
            }
        }
    }

    cout<<"NO\n";

    
    //cout<<"\n";
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

// int n, m;
// vi del;

// bool possible(int i, int j){
//     return (i>=0 && i<n && j>=0 && j<m);
// }

// vector<char> dir;
// string ans;
// vector<vi> vis, allw, par;

// signed main()
// {
//     fast_io
    
//     cin>>n>>m;
//     vector<vector<char>> mat(n, vector<char>(m));
//     queue<pair<int , pair<int, int>>> q;
//     vis.resize(n, vi(m, 0));

//     pair<int, int> start;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>mat[i][j];
//             if(mat[i][j]=='M'){
//                 q.push({0, {i, j}});
//                 vis[i][j] = 1;
//             }else if(mat[i][j] == 'A'){
//                 if(i==0 || j==0 || i==n-1 || j==m-1){
//                     cout<<"YES"<<nl<<0<<nl<<nl;
//                     return 0;
//                 }
//                 start = {i, j};
//             }
            
//         }
//     }

//     del.assign({-1, 0, 1, 0, -1});
//     dir.assign({'U', 'R', 'D', 'L'});

//     vector<vi> saf(n, vi(m, 1e9));

//     while(!q.empty()){
//         auto [d, node] = q.front();
//         auto [i, j] = node;
//         saf[i][j] = min(saf[i][j], d);
//         q.pop();
//         for(int k=0; k<4; k++){
//             int x = i+del[k], y = j+del[k+1];
//             if(possible(x, y) && !vis[x][y] && mat[x][y]!='#'){
//                 vis[x][y] = 1;
//                 q.push({d+1, {x, y}});
//             }
//         }
//     }

//     allw.resize(n, vi(m, 0));
//     vis.assign(n, vi(m, 0));
//     q.push({0, start});
//     vis[start.first][start.second] = 1;

//     par.resize(n, vi(m, 0));
//     par[start.first][start.second] = -1;

//     while(!q.empty()){
//         auto [d, node] = q.front();
//         auto [i, j] = node;
//         q.pop();

//         if(d<saf[i][j])
//             allw[i][j]=1;
//         else
//             continue;
        
//         if(i==0 || j==0 || i==n-1 || j==m-1){
//             int p = par[i][j];
//             int x = i,  y = j;
//             while(p!=-1){
//                 ans.push_back(dir[p]);
//                 x = x - del[p], y = y - del[p+1];
//                 p = par[x][y];
//             }
//             reverse(ans.begin(), ans.end());
//             cout<<"YES"<<nl;
//             cout<<ans.size()<<nl<<ans<<nl;
//             return 0;
//         }

//         for(int k=0; k<4; k++){
//             int x = i+del[k], y = j+del[k+1];
//             if(possible(x, y) && !vis[x][y] && mat[x][y]!='#'){
//                 vis[x][y] = 1;
//                 par[x][y] = k;
//                 q.push({d+1, {x, y}});
//             }
//         }
//     }
//     if(ans.size()==0){
//         cout<<"NO"<<nl;
//         return 0;
//     }

//     //cout<<"\n";
//     return 0;
// }