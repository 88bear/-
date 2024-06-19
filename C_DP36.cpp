#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 1005;
int values[3] = {5, 2, 0};
int cnt[3];
int n, x, y, mx;

int dfs(int id, int sum, int pos){
    if (id > x || sum < 0) return 0;
    if (id == x && sum == 0){
        mx = max(mx, *max_element(cnt, cnt+3));
        if (mx < 2) mx = 0;
        return 1;
    }
    int res = 0;
    for(int i = pos; i < 3; ++i){
        cnt[i]++;
        res += dfs(id+1, sum - values[i], i);
        cnt[i]--;
    }
    return res;
}

int main() {
    cin >> n;
    while(n--){
        memset(cnt, 0, sizeof cnt);
        mx = 0;
        cin >> x >> y;
        int valid = dfs(0, y, 0);
        if(!valid) cout << "-1" << '\n';
        else if(!mx) cout << "0" << '\n';
        else cout << valid << " " << mx << '\n';
    }
    return 0;
}
