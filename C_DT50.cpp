#include <bits/stdc++.h>
using namespace std; 
int main(){ 
    int n; 
    cin >> n; 
    while(true){ 
        vector<int> train(n); 
        for(int i = 0; i < n; i++)
            if(!(cin >> train[i])){ 
                goto end;
            }
        int a = 1, b = 0; 
        stack<int> c;
        while(b < n){ 
            if(!c.empty() && c.top() == train[b]){ 
                c.pop(); 
                b++; 
            } 
            else if(a <= n){ 
                c.push(a); 
                a++;
            }
            else
                break; 
        }
        cout << (b == n ? "YES" : "NO") << '\n';
    }
    end:return 0;
}