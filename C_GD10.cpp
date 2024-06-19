#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, num2 = 0, k = 0, cnt = 0;
    cin >> num;
    for(int i = 10000; i < 100000; i++){
        if(i % num == 0){
            num2 = i / num;
            string str1 = to_string(i);
            string str2 = to_string(num2);

            vector<int> arr(10, 0);
            for(char c : str1){
                arr[c - '0']++;
            }
            for(char c : str2){
                arr[c - '0']++;
            }
            if(str2.length() == 4){
                arr[0] = 1;
            }
            for(k = 0; k < 10; k++){
                if(arr[k] != 1) break;
            }
            if(k == 10){
                printf("%05d / %05d = %d\n", i, num2, num);
                cnt++;
            }
        }
    }
    if(cnt == 0)
        printf("No solutions for %d.\n", num);

    return 0;
}
