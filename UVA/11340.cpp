#include <bits/stdc++.h>
using namespace std;

int cost[513];

int main(){
        int n;
        cin >> n;
        while(n--){
                int k;  cin >> k;
                memset(cost, 0, sizeof(cost));
                while(k--){
                        unsigned char c; cin >> c;
                        int v;  cin >> v;
                        cost[(int)c] = v;
                }
                int m;  cin >> m;       
                long long ans = 0;
                for(int i = 0; i < m; i++){
                        char stc[12000];
                        cin.getline(stc, 12000, '\n');
                        if(stc[0] == '\0' && i == 0){
                                i--;    continue;
                        }
                        //cout << strlen(stc) << endl << endl;
                        for(int i = 0; i < strlen(stc); i++){
                                unsigned char c = stc[i];
                                ans += cost[(int)c];
                        }
                }
                cout << ans/100 << "." <<  setfill('0') << setw(2) << ans%100 << "$" << endl;
        }

}
