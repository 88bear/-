#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, h, k;
bool vis[1005][1005];
int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int t;
void dfs(int x, int y){
    if(x == h && y == k && vis[x][y]){
        t++;
        return;
    }
    for(int i=0; i<8; ++i){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx >= 0 && dx <= n && dy >= 0 && dy <= m && !vis[dx][dy]){
            vis[dx][dy] = true;
            dfs(dx, dy);
            vis[dx][dy] = false;
        }
    }
}
signed main(){
    while(cin >> n >> m >> h >> k){
        t = 0;
        memset(vis, 0, sizeof vis);
        dfs(h, k);
        cout << t << '\n';
    }
    return 0;
}