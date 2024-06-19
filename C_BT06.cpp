#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int n,m; 
    cin >> n >> m;
    while(true){ 
    int l = ceil(n*0.75); 

    if(n-l < m) break; 

    n = n - l + m;
    }
    cout << n - ceil(n * 0.75) << '\n'; 
    return 0; 
}