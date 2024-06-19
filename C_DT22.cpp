#include <bits/stdc++.h>
using namespace std;

int checkBalancedBrackets(const string& input){
    stack<char> s;
    for(char ch : input){
        if(ch == '('){
            s.push(ch);
        }else if (ch == ')'){
            if(s.empty()){
                return -1;
            }
            s.pop();
        }
    }
    return s.empty() ? 1 : -1;
}

int main(){
    string input;
    while(getline(cin, input)){
        if(input == "end") break;
        cout << checkBalancedBrackets(input) << '\n';
    }
    return 0;
}