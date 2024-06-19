#include <bits/stdc++.h>
using namespace std;
#define N 10005

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            for(int j = x; j <= 10000; ++j){
                if(dp[j - x] != INT_MAX){
                    dp[j] = min(dp[j], dp[j-x] + 1);
                }
            }
        }
        int tar;
        cin >> tar;
        if(dp[tar] == INT_MAX)
            cout << 0 << '\n';
        else
            cout << dp[tar] << '\n';
    }
    return 0;
}