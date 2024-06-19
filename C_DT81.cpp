#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int x;
    cin >> x;
    nums[n] = x;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i)
        cout << nums[i] << '\n';

    return 0;
}
