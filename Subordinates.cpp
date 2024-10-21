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

struct TreeNode{
    int par;
    vector<int> children;
};

int solve(int i, vector<TreeNode> &nodes, vi &dp){
    if(dp[i] != -1)
        return dp[i];

    dp[i] = 0;

    for(auto c:nodes[i].children){
        dp[i] += solve(c, nodes, dp);
    }

    return dp[i]+1;
}


signed main()
{
    fast_io
    
    int n;
    cin>>n;
    vector<TreeNode> nodes(n+1);
    for (int i = 2; i <= n; i++){
        int x;
        cin>>x;
        nodes[i].par = x;
        nodes[x].children.push_back(i);
    }

    vector<int> dp(n+1, -1);

    solve(1, nodes, dp);

    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<nl;


    
    //cout<<"\n";
    return 0;
}