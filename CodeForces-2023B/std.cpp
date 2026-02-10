#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>>g(n+1);
    vector<int>inder(n+1,0);
    vector<int>a(n+1);
    vector<int>prv(n+1,0);
    vector<int>b(n+1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        prv[i] = prv[i-1] + a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> b[i];
        if(i > 1){
            g[i].push_back({i-1,0});
            inder[i-1]++;
        }
        g[i].push_back({b[i],a[i]});
        inder[b[i]]++;
        
    }
    vector<int>tim(n+1,INF);
    tim[1]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [val,u] = pq.top();
        pq.pop();
        if(val > tim[u])continue;
        for(auto [v,w] : g[u]){
            if(tim[v] > tim[u]+w){
                tim[v] = tim[u]+w;
                pq.push({tim[v],v});
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,prv[i]-tim[i]);
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

// by vanadium-23