#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;  // 2^20 > 1e5

vector<int> adj[MAXN];
vector<int> ch[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];
int n, m, root;

bool cmp(int a,int b){
    return depth[a] < depth[b];
}

// 预处理：计算每个节点的深度和2^k级祖先
void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    parent[u][0] = p;
    for (int k = 1; k < LOG; ++k) {
        parent[u][k] = parent[parent[u][k-1]][k-1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            ch[u].push_back(v);
            dfs(v, u);
        }
    }
}

// 查找u和v的最近公共祖先
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    // 将u提到与v同一深度
    for (int k = LOG - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = parent[u][k];
        }
    }
    if (u == v) {
        return u;
    }
    // 同时向上跳
    for (int k = LOG - 1; k >= 0; --k) {
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}

void solve() {
    cin >> n >> m;
    root = 1;
    for(int i = 1;i <= n;i++){
        adj[i].clear();
        ch[i].clear();
        depth[i]=0;
        for(int j = 0;j < LOG;j++){
            parent[i][j] = 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 预处理
    dfs(root, 0);

    while(m--){
        int k;cin >> k;
        vector<int>arr(k+1);
        for(int i = 1;i <= k;i++){
            int tmp;cin >> tmp;
            arr[i] = parent[tmp][0];
            // cout << parent[tmp][0] << ' ';
        }
        // cout << endl;
        sort(arr.begin()+1,arr.end(),cmp);
        bool can = true;
        for(int i = 1;i < k;i++){
            int u = arr[i];
            int v = arr[i+1];
            if(lca(u,v) == u || lca(u,v) == v){

            }else{
                cout << "NO\n";
                can = false;
                break;
            }
        }
        if(can)cout << "YES\n";
    }
    return;
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