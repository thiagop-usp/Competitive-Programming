// Source: https://codeforces.com/blog/entry/18051
// I thought the source was a good resource but the explanation behind it wasn't given too much thought.

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int n;                  // input array size
int st[2*MAXN];         // array that will contain both the input values and the segtree itself 

/*
PS.:
it's stored continuously, such that from 1 to n-1 (inclusive), you'll have the built segtree
whereas from n to 2n-1 (inclusive) you'll have the input values.
*/

void build(){
	for(int i = n-1; i>0; i--) 
	    st[i]=st[i+i]+st[i+i+1]; //building the segtree (top-down)
}

//in case you want to update the element at position p to an arbitrary x value:
/*
So basically we'll start from the node p itself, and go up the tree, dividing by 2 (a change in p will only affect what's above it).
note that with st[p/2]=st[p]+st[p+1] we are reconstructing the tree upwards, given that p/2 is the parent of the node p, and p+1 is p/2's
other child.
*/

void update(int p, int x){
  p+=n;
	for(st[p] = x; p>0; p/=2) 
	    st[p/2]=st[p]+st[p+1];
}

//Additionally, if we want to know what is the sum of all elements between l and r (inclusive for l but not for r):
// P.S. in case you want it to be inclusive for r aswell, just change r+=n with r+=n+1

/*
if(l&1) is equivalent to if(l is odd). In this case, if l is odd, then it can be written as (2k+1), which means that l is 
the right child of p. But since l is the left corner of the range that's been looked at, then it means that l must be included
in our query, but p mustn't. It's like this:

              parent
  left child         right child

  but,
    parent:       p
    left child:   2p
    right child:  2p+1 (which is an odd number)

  So in this case, the right child will be included in the query, but the left won't, so we can't take the parent.
  So what we'll do is first take the right child (ans+=st[l]) and then go to the next node adjacent to p (when the next
  iteration happens, l will become (l+1)/2 ). All of that can be written as ans+=st[l++].
  
It works similarly with the second condition
if(r&1) is equivalent to if(r is odd). Since r is the right corner and we don't want to take it (our query isn't inclusive
on the right side) we'll first subtract one from r (if r is odd, then it's 2k+1, thus it'll become 2k, which means it's not 
the right child anymore, but rather the left child) and then we'll add it to our query.
*/

int query(int l, int r){
	int ans = 0;
	for(l+=n, r+=n; l<r; l/=2, r/=2){
		if(l&1) ans+=st[l++];
		if(r&1) ans+=st[--r];
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 0; i<n; i++) 
	    cin >> st[i+n];
	    
	build();
  return 0;
}
