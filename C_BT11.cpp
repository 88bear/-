#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> feeds(n);
    for(int i = 0; i < n; ++i){
        cin >> feeds[i].first >> feeds[i].second;
    }

    int maxmoney = 100;
    vector<int> dp(maxmoney+1, 0);

    for(const auto& feed : feeds){
        int cost = feed.first;
        int fullness = feed.second;
        for(int j = maxmoney; j >= cost; --j){
            dp[j] = max(dp[j], dp[j - cost] + fullness);
        }
    }

    cout << dp[maxmoney] << '\n';
    return 0;
}
