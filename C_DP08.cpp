#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(15005, 0);
    vector<int> d = {1, 5, 10, 50};
    dp[0] = 1;

    for(int i = 0; i < 4; i++)
        for(int j = d[i]; j <= 15000; j++)
            dp[j] += dp[j - d[i]];

    cout << dp[n] << '\n';
    return 0;
}
