#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    char ch;
    while (cin >> x >> ch >> y) {
        vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                if (i == 0 && j == 0)
                    continue;
                if(i)
                    dp[i][j] += dp[i-1][j];
                if(j > 0 && i >= j)
                    dp[i][j] += dp[i][j-1];
            }
        }
        cout << dp[x][y] << '\n';
    }
    return 0;
}
