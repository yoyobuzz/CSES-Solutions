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

bool dp[101][100001];

void solve(int i, int sum, set<int>& st, vi& a){
    if(i==0)
        return;
    if(dp[i][sum])
        return;
    dp[i][sum] = 1;
    st.insert(sum+a[i-1]);
    solve(i-1, sum+a[i-1], st, a);
    solve(i-1, sum, st, a);
}

signed main()
{
    fast_io
    
    int n;
    cin>>n;
    vi a(n);
    int sum = 0;
    for(auto &i:a){ 
        cin>>i;
        sum+=i;
    }
    set<int> st;
    memset(dp, 0, sizeof dp);
    solve(n, 0, st, a);

    cout<<st.size()<<nl;
    for(auto i:st)
        cout<<i<<' ';
    cout<<nl;
    //cout<<"\n";
    return 0;
}