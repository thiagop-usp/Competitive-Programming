#include <bits/stdc++.h>
using namespace std;

int main(){
        int n = 1;

        while(n){
                priority_queue<int, vector<int>, greater<int>> pq;      
                cin >> n;
                if(!n) return 0;
                for(int i = 0; i < n; i++){
                        long long x;    cin >> x;
                        pq.push(x);
                }
                long long ans = 0;
                while(pq.size() > 1){
                        long long int a = pq.top();
                        pq.pop();
                        long long int b = pq.top();
                        pq.pop();
                        pq.push(a+b);
                        ans+=a+b;
                }
                cout << ans << endl;
        }

}
