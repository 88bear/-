#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<string> s(n);
        vector<int> a(n), b(n), c(n);
        vector<int> dp(2400, 0), best(2400, -1);
        for(int i = 0; i < n; i++) {
            cin >> s[i] >> a[i] >> b[i] >> c[i];
        }
        int ret = 0, end = 0;
        for(int i = 0; i < 2400; i++){
            if(i > 0 && dp[i] <= dp[i-1]){
                best[i] = -1;
                dp[i] = dp[i-1];
            }
            for(int j = 0; j < n; j++){
                if(a[j] == i){
                    if(dp[b[j]] <= dp[i] + c[j]){
                        dp[b[j]] = dp[i] + c[j];
                        best[b[j]] = j;
                    }
                }
            }
            if(dp[i] > ret){
                ret = dp[i];
                end = i;
            }
        }

        stack<int> stk;
        for(int i = end; i > 0;){
            if(best[i] == -1){
                i--;
            }else{
                stk.push(best[i]);
                i = a[best[i]];
            }
        }

        while(!stk.empty()){
            cout << s[stk.top()] << " ";
            stk.pop();
        }
        cout << ret << '\n';
    }

    return 0;
}
