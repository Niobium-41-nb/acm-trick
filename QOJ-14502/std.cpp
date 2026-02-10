#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+1;
const int MOD = 1e9;
const int INF = MOD;
int arr[5001][5001];
void solve() {
    int n,q;
    cin >> n >> q;
    // vector<vector<int>>arr(n+1,vector<int>(n+1,INF));
    for(int i = 1;i <= n-1;i++){
        string ss;cin >> ss;
        for(int j = i+1;j <= n;j++){
            char c = ss[j-(i+1)];
            if(c == '1'){
                arr[i][j] = 0;
                arr[j][i] = INF;
            }else{
                arr[j][i] = 0;
                arr[i][j] = INF;
            }
        }
    }
    if(n <= 20){
        // for(int i = 1;i <= n;i++){
        //     for(int j = 1;j <= n;j++){
        //         if(arr[i][j] == INF){
        //             cout << "INF ";
        //         }else{
        //             cout << arr[i][j] << ' ';
        //         }
        //     }
        //     cout << endl;
        // }
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]+1);
                }
            }
        }
        // for(int i = 1;i <= n;i++){
        //     for(int j = 1;j <= n;j++){
        //         if(arr[i][j] == INF){
        //             cout << "INF ";
        //         }else{
        //             cout << arr[i][j] << ' ';
        //         }
        //     }
        //     cout << endl;
        // }
        while(q--){
            int x,y;
            cin >> x >> y;
            if(arr[x][y] == INF){
                printf("%d\n",-1);
                continue;
            }
            printf("%d\n",arr[x][y]);
        }
    }else{
        while(q--){
            int x,y;
            cin >> x >> y;
            if(arr[x][y] == INF){
                printf("%d\n",1);
                continue;
            }
            printf("%d\n",arr[x][y]);
        }
    }
}

int main() {
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