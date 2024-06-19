#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int temp;
    cin >> temp;
    int x, y;
    while(cin >> x >> y){
        vector<vector<int>> v(y+1, vector<int>(5, 0));
        v[1][0] = x;
        for (int i = 2; i <= y; ++i) {
            v[i][0] = v[i-1][2] + v[i-1][3];
            v[i][1] = v[i-1][0];
            v[i][2] = v[i-1][1];
            v[i][3] = v[i-1][2];
            v[i][4] = v[i-1][3];
        }
        cout << v[y][0] + v[y][1] + v[y][2] + v[y][3] + v[y][4] << '\n';
    }
    return 0;
}
