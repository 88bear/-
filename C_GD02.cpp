#include <iostream>
using namespace std;

int main() {
    int n, t = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        t += num;
    }
    cout << (t % 2 == 0 ? "YES" : "NO") << '\n';
    return 0;
}
