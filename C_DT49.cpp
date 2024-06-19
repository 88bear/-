#include <bits/stdc++.h>
using namespace std;

int func(const string exp){
    stack<int> s;
    stringstream ss(exp);
    string token;
    
    while(ss >> token){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if(token == "+") s.push(a + b);
            else if(token == "-") s.push(a - b);
            else if(token == "*") s.push(a * b);
            else if(token == "/") s.push(a / b);
        }else{
            s.push(stoi(token));
        }
    }
    
    return s.top();
}

int main(){
    string exp;
    while(getline(cin, exp)){
        cout << func(exp) << endl;
    }
    return 0;
}
