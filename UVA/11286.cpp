#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back

int main(){
	
	while(1){
		map<vector<int>, int> m;
		vector<vector<int>> inp;
		int n;
		cin >> n;
		if(n == 0) return 0;
		for(int i = 0; i < n; i++){
			vector<int> line;
			for(int j = 0; j < 5; j++){
				int x;	cin >> x;
				line.pb(x);
			}
			inp.pb(line);
			sort(line.begin(), line.end());
			m[line]++;
		}
		int ans = 0;

		int maxv = 0;

		for(auto i : m){
			maxv = max(maxv, i.second);	
		}

		for(auto i : inp){
			vector<int> p = i;
			sort(p.begin(), p.end());
			if(m[p] == maxv) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}
