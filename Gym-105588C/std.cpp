#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, k; cin >> n >> k;
    ll p = 1, cnt = 1;
    while (p <= n) {
        if (cnt < k) {
            ll val = (min(n, cnt * k) - p) / cnt * cnt;
            if (val == 0) break;
            p += val; cnt++;
        } else {
            cnt = (p - 1) / (k - 1) + 1;
            if (p + cnt <= n) p += cnt;
            else break;
        }
    }
    cout << p << endl;
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