#include <iostream>
using namespace std;

int main(){
    int data[101], i, j, m = 1, tmp1, tmp2, boom, num;
    for(i = 0; m < 100; i++){
        tmp1 = i; tmp2 = i;
        boom = 0; data[0] = 0;
        while(tmp1 > 0){
            if(tmp1 % 7 == 0){
                boom = 1;
                break;
            }
            else
                tmp1 -= 5;
        }

        while(tmp2 > 0 && boom == 0){
            if(tmp2 % 5 == 0){
                boom = 1;
                break;
            }
            else
                tmp2 -= 7;
        }

        if(boom == 1){
            data[m] = i;
            m++;
        }
    }
    while(cin >> num){
        cout << data[num - 1] << '\n';
    }
    return 0;
}
