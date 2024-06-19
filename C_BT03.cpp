#include <bits/stdc++.h>
#define int long long
using namespace std;

bool square(vector<int>& stk, vector<int>& s, int idx, int sl){
    if(idx == stk.size()){
        return s[0] == sl && s[1] == sl && s[2] == sl && s[3] == sl;
    }

    for(int i = 0; i < 4; i++){
        if(s[i] + stk[idx] <= sl){
            s[i] += stk[idx];
            if(square(stk, s, idx+1, sl)){
                return true;
            }
            s[i] -= stk[idx];
        }
    }
    return false;
}

signed main(){
    int n;
    cin >> n;

    vector<int> stk(n);
    int total_l = 0;

    for(int i = 0; i < n; i++){
        cin >> stk[i];
        total_l += stk[i];
    }

    if(total_l % 4 != 0){
        cout << "no" << '\n';
        return 0;
    }
    int sl = total_l / 4;

    sort(stk.rbegin(), stk.rend());

    vector<int> s(4, 0);

    if(square(stk, s, 0, sl)){
        cout << "yes" << '\n';
    }else{
        cout << "no" << '\n';
    }
    return 0;
}
