#include <bits/stdc++.h>
using namespace std;

vector<int> vet; // vector that will contain the input sequence
vector<int> I;   // vector that contains the lowerbounds to each element in vet, sorted increasingly 
const int inf = 0x3f3f3f3f;
int lis(int n){
	I.push_back(-inf);
	int llength = 0; // size of LIS
	for (int i = 0; i < n; ++i)
	{
		auto it = lower_bound(I.begin(), I.end(), vet[i]);
		
		/* if vet[i] has its lowerbound in I (the lowest among the numbers that are greater or equal to vet[i]), 
		then that element in I should be replaced
		*/
		if(it != I.end()) *it = vet[i]; 
		
		// In case that doesn't happen, that element must be added to the vector, and the LIS size will be increased
		else {
			I.push_back(vet[i]);
			llength++;
		}
		
		/*To make it easier to understand:
		
		I: -inf | 4 | 6 | 7
		Let's say vet[i] is 3, that way, its lowerbound is in I and it's 4 (the lowest among the numbers that
		are greater than 3)
		
		That way, the vector will be:
		I: -inf | 3 | 6 | 7
		
		Let's say now that vet[i] is 8, which doesnt have a lowerbound in I, then, the vector will be:
		I: -inf | 3 | 6 | 7 | 8
		
		and the new LIS size will be 4 (we don't consider -inf, as it was only added at first so that the first element
		in vet would have a lowerbound in I, given that -inf is, in theory, lower than any other number
		*/
	}
	return llength;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		vet.push_back(x);
	}

	cout << lis(n);

	return 0;
}
