#include <bits/stdc++.h>
using namespace std;

int main() {
    const vector<int> coin = {1, 5, 10, 50};
    int k, n, m, c;

    while(cin >> k){
        cin.ignore(1, ',');
        cin >> n;
        cin.ignore(1, ',');
        cin >> m;
        c = (n == 1) ? 17 : 25;
        c *= m;
        int rem = k - c;
        vector<int> bag(4, 0);
        for(int i = 3; i >= 0; --i){
            if(rem >= coin[i]){
                bag[i] += (rem / coin[i]);
                rem %= coin[i];
            }
        }
        bool f = false;
        for(int i = 0; i < 4; ++i){
            if(bag[i] > 0){
                if(f) cout << ',';
                cout << "Coin " << coin[i] << ":" << bag[i];
                f = true;
            }
        }
        cout << '\n';
    }
    return 0;
}