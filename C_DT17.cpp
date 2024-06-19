#include <bits/stdc++.h>
using namespace std;

bool func(const string& expr){
    stack<char> s;
    for(char ch : expr){
        if(ch == '('){
            s.push(ch);
        }else if (ch == ')'){
            if(s.empty()){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string input;
    while(getline(cin, input)){
        if(func(input))
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
        
    }
    return 0;
}
