#include <bits/stdc++.h>
#define N 1005
using namespace std;

int dp[N][N];
string s;

bool bracket(char ch1, char ch2){
    if(ch1 == '(' && ch2 == ')') return true;
    if(ch1 == '[' && ch2 == ']') return true;
    if(ch1 == '{' && ch2 == '}') return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        memset(dp, 0, sizeof(dp));
        int n = s.length();
        for(int len = 1; len < n; ++len){
            for(int i = 0; i + len < n; ++i){
                int j = i + len;
                if(bracket(s[i], s[j])){
                    dp[i][j] = dp[i+1][j-1] + 1;
                }
                for(int k = i; k < j; ++k){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[0][n-1] << '\n';
    }
    return 0;
}
