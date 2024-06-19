#include <iostream>
using namespace std;

int f(int n, int k){
    if(n == k || n < 2*k){
        return 1;
    }else{
        int num = 0;
        for(int i = k; i < n; ++i){
            if(n-i >= i){
                num += f(n-i, i);
            }
        }
        return num+1;
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << f(n, 1) << '\n';
    }
    return 0;
}
