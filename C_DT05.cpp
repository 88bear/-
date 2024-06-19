#include <bits/stdc++.h>
using namespace std;

vector<int> lis(vector<int>& nums){
    int n = nums.size();
    vector<int> lis;
    vector<vector<int>> dp(n);

    dp[0].push_back(nums[0]);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(nums[i] > nums[j] && dp[j].size() > dp[i].size()){
                dp[i] = dp[j];
            }
        }
        dp[i].push_back(nums[i]);
    }

    for(int i = 0; i < n; ++i){
        if(dp[i].size() > lis.size()){
            lis = dp[i];
        }else if (dp[i].size() == lis.size() && dp[i] > lis) {
            lis = dp[i];
        }
    }
    return lis;
}

int main(){
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> nums;
    string tmp;
    while(getline(ss, tmp, ',')){
        nums.push_back(stoi(tmp));
    }

    vector<int> lis = lis(nums);

    for(int i = 0; i < lis.size(); ++i){
        cout << lis[i];
        if(i != lis.size() - 1) cout << ',';
    }
    cout << '\n';
    return 0;
}
