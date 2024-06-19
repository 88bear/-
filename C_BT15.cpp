#include <bits/stdc++.h>
using namespace std;

int q[10];
int n, x, y, ans;

bool canpq(int k){
    for(int i = 0; i < k; ++i){
        if(q[i] == q[k] || abs(k-i) == abs(q[i] - q[k]))
            return false;
    }
    return true;
}

void dfs(int k){
    for(int j = 0; j < n; ++j){
        if(k == x){
            q[k] = y;
            j = n;
        }
        else
            q[k] = j;

        if(k == n-1 && canpq(k)){
            ans++;
            return;
        }
        else if(canpq(k))
            dfs(k+1);
    }
}

int main(){
    while(cin >> n >> x >> y){
        memset(q, 0, sizeof q);
        ans = 0;
        dfs(0);
        if(ans)
            cout << "YES" << '(' << ans << ")\n";
        else
            cout << "NO\n";
    }
    return 0;
}
