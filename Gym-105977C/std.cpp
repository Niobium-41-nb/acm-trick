#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n;
bool check(int num,const vector<int>&arr){
    vector<int>tmp(n+1,0);
    for(int i = 1;i <= n;i++){
        if(arr[i] >= num){
            tmp[i] = 1;
        }else{
            tmp[i] = 0;
        }
    }
    vector<int>t;
    for(int i = 1;i <= n;i++){
        if(t.size() >= 2 && t[t.size()-1] == 0 && t[t.size()-2] == 0){
            t.pop_back();
        }else{
            t.push_back(tmp[i]);
        }
    }
    vector<int>cnt(2,0);
    for(auto i : t){
        cnt[i]++;
    }
    return cnt[1] >= cnt[0];

}
void solve() {
    cin >> n;
    vector<int>arr(n+1,0);
    int l=0,r=0;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        r = max(r,arr[i]);
    }r++;

    while(r-l > 1){
        int mid = (l+r)/2;
        if(check(mid,arr))l =mid;
        else r = mid;
    }
    cout << l << endl;
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