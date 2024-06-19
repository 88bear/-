#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 1e9+7;
    vector<int> v1(n, 0), v2(n, 0);
    v1[1] = 1;
    v2[1] = 0;
    
    for(int i = 2; i < n; i++){
        v1[i] = v1[i-1] + v2[i-1];
        v2[i] = v1[i-1];
        v1[i]++;
    }
    
    int x;
    while(cin >> x){
        cout << v1[x] << " " << v2[x] + 1 << '\n';
    }

    return 0;
}