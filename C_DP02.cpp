#include <bits/stdc++.h>
using namespace std;

int main() {
    int temp;
    cin >> temp;
    int n, m, x;
    while(cin >> n >> m){
        set<int> sa, sb;
        sa.insert(0);
        for(int i = 0; i < n; i++){
            cin >> x;
            sb = sa;
            for(auto it = sa.begin(); it != sa.end(); it++){
                if(*it + x <= 200000)
                    sb.insert(*it + x);
            }
            sa = sb;
        }

        int ret = 0;
        while(m--){
            cin >> x;
            ret += (sa.find(x) != sa.end());
        }
        cout << ret << '\n';
    }
    return 0;
}