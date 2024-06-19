#include <bits/stdc++.h>
using namespace std;

int main(){
    int temp;
    cin >> temp;
    int n;
    while(cin >> n){
        vector<vector<int>> g(n, vector<int>(n));
        vector<int> used(n, 0);
        vector<int> cost(n, INT_MAX);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j){
                cin >> g[i][j];
            }
        }
        int ret = 0;
        cost[0] = 0;
        for (int i = 0; i < n; ++i) {
            int mx = INT_MAX, mi = -1;

            for(int j = 0; j < n; ++j){
                if(cost[j] < mx && used[j] == 0){
                    mx = cost[j];
                    mi = j;
                }
            }

            ret += mx;
            used[mi] = 1;

            for(int j = 0; j < n; ++j){
                if(g[mi][j]){
                    cost[j] = min(cost[j], g[mi][j]);
                }
            }
        }

        cout << ret << '\n';
    }
    return 0;
}