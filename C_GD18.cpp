#include <bits/stdc++.h>
using namespace std;

char know[20][20];

int main(){
    int maxi = 0, tmpj = 0;
    stringstream ss("");
    string input;

    while(getline(cin, input)){
        if(input.empty()) break;
        ss.str("");
        ss.clear();
        ss << input;
        tmpj = 0;
        while(ss >> know[maxi][tmpj++]){}
        maxi++;
    }

    int maxj = strlen(know[0]);
    int table[maxj];
    memset(table, 0, sizeof(table));

    for(int i = 0; i < maxi; i++){
        for(int j = 0; j < maxj; j++){
            if(know[i][j] == 'Y')
                table[j]++;
        }
    }

    sort(table, table + maxj);
    
    if(table[maxj-1] == table[maxj-2])
        cout << "NO!" << '\n';
    else
        cout << table[maxj-1] << '\n';

    return 0;
}
