#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a,int b){
    return a * b / gcd(a,b);
}
struct qj{
    int a,b,cnt;
};
void solve() {
    int a,b;
    cin >> a >> b;
    queue<qj>q;
    qj tmp = {a,b,0};
    q.push(tmp);
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        if(a.a == 0 && a.b == 0){
            cout << a.cnt << endl;
            return;
        }
        q.push({a.a-gcd(a.a,a.b),a.b,a.cnt+1});
        q.push({a.a,a.b-gcd(a.a,a.b),a.cnt+1});
    }  
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