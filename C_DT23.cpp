#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	vector<string> tmp;
	while(getline(cin, s)){
		if(s == "end")
			break;
		int ans = 0;
		string token;
		stringstream ss(s);
		while(getline(ss, token, ' ')){
			tmp.push_back(token);
		}
		stringstream sss(tmp[0]);
		int t;
		sss >> t;
		ans = t;
		for(int i = 0; i < tmp.size(); i++){
            if(tmp[i] == "+"){
                stringstream t1(tmp[i+1]);
                int v;
                t1 >> v;
                ans += v;
            }
            else if(tmp[i] == "-"){
                stringstream t2(tmp[i+1]);
                int v;
                t2 >> v;
                ans -= v;
            }
		}
		cout << ans << '\n';
	}
	return 0;
}