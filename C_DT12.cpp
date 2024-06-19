#include <bits/stdc++.h>
using namespace std;

int main(){
    string buf;
    while(getline(cin, buf)){
        for(int i = buf.length() - 1; i >= 0; i--)
            cout << buf[i];
        cout << '\n';
    }
    return 0;
}
