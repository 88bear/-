#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long cnt(const string& str){
    int n = str.length();
    map<char, int> charcnt;

    for(char ch : str){
        charcnt[ch]++;
    }

    unsigned long long numerator = factorial(n);
    unsigned long long denominator = 1;


    for(const auto& pair : charcnt){
        denominator *= factorial(pair.second);
    }
    return numerator / denominator;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> num(n);
    string word[n];
    for(int i = 0; i < n; ++i){
        cin >> word[i];
        num[i] = cnt(word[i]);
    }
    int max = 0;
    for(int i = 0; i < n; ++i){
        if(max < num[i])
            max = num[i];
    }
    for(int i = 0; i < n; ++i){
        if(num[i] == max)
            cout << word[i] << '\n';
    }
    
    return 0;
}
