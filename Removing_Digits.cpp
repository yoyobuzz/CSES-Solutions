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

int freq[10];
int dp[1000001];

signed main()
{
    fast_io
    
    int N;
    cin>>N;
        
    memset(freq, 0, sizeof(freq));

    dp[0] = 0;
    dp[1] = 1;

    for(int n=2; n<=N; n++){
        int ans = INT_MAX;
        int temp = n;
        memset(freq, 0, sizeof(freq));
        while(temp>0){
            freq[temp%10]++;
            temp/=10;
        }
        for(int i=9; i>0; i--){
            if(freq[i]>0){
                ans = min(ans, 1 + dp[n-i]);
            }
        }
        dp[n] = ans;
    }
    cout<<dp[N]<<"\n";

    return 0;
}