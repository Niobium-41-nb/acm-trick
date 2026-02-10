#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k, sum=0;
    cin >> n >> m >> k;
    
    vector<int>a(n+1,0);
    vector<int>b(m+1,0);
    vector<int>f((1 << m));
    vector<int>ccnt(1 << m);

    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> b[i];
    }
    for(int k = 0;k < (1 << m);k++){
        f[k] = (1 << 60)-1;
        ccnt[k]=0;
        for(int j = 1;j <= m;j++){
            if((k & (1 << (j-1)))){
                f[k] = (f[k] & b[j]);
                ccnt[k]++;
            }
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,INF));
    for(int i = 1;i <= n;i++){
        dp[i][0] = a[i];
        for(int k = 0;k < (1 << m);k++){
            int sum = (a[i] & f[k]);
            int cnt = ccnt[k];
            dp[i][cnt] = min(dp[i][cnt],sum);
            // cout << endl;
        }
    }
    vector<int>arr;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            arr.push_back(dp[i][j-1]-dp[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    for(int i = 0;i < k;i++){
        sum -= arr[i];
    }
    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// by vanadium-23