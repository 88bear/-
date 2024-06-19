#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(getline(cin, str)){
        unordered_map<char, int> freq;
        for(char c : str){
            freq[c]++;
        }
        char maxChar = '\0';
        int maxFreq = 0;
        for(const auto& entry : freq){
            if(entry.second > maxFreq){
                maxFreq = entry.second;
                maxChar = entry.first;
            }
        }

        cout << maxChar << '\n';
    }
    return 0;
}
