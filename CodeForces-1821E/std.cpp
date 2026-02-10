#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int k;
    string s;
    cin >> k >> s;
    
    int n = s.size();
    vector<int> st;  // 栈存储左括号位置
    vector<int> d;   // 存储每个括号对的内部括号对数
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else {  // s[i] == ')'
            // 计算当前匹配括号对的内部括号对数
            int left_idx = st.back();
            st.pop_back();
            d.push_back((i - left_idx - 1) / 2);
        }
    }
    
    // 排序，使得最大的值在前面
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    
    int ans = 0;
    // 跳过前k个最大的（通过k次操作消除它们）
    for (int i = k; i < d.size(); i++) {
        ans += d[i];
    }
    
    cout << ans << endl;
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