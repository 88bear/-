#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum = 0, t;
    while(cin >> n){
        sum = 0;
        t = 0;
        for(int i = 1; i <= n; i++){
            if(sum + i > n) break;
        sum += i;
        t++;
        }
        cout << t << '\n';
    }
    return 0;
}