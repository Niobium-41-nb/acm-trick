#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int>arr(k+1,0);
    for(int i = 1;i <= k;i++){
        cin >> arr[i];
    }
    vector<int>dp(n+1,0);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            if(i-arr[j] >= 0)dp[i] = max({dp[i],i-dp[i-arr[j]]});
        }
    }
    cout << dp[n] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// by vanadium-23