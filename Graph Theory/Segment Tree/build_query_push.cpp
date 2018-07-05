#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e5 + 5;

ll st[4*M];
ll v[M];
ll lazy[4*M];

//function to build the segment tree
void build(int p, int l, int r){
    if(l==r) st[p]=v[l]; // in case the interval contains only one element
    else{
        int mid = (l+r)>>1; // keep dividing it into two parts (recursively) and assigning values
        build(2*p, l, mid);
        build(2*p+1, mid+1, r);
        st[p]=st[2*p]+st[2*p+1];
    }
}

//function to push (propagate) the numbers stacked in the lazy array
void push(int p, int l, int r){
    if(lazy[p]){ //if the number stacked isn't 0
        st[p]+=lazy[p]*(r-l+1); // propagate that number times the height we're at

        if(l!=r){ //update to make things right
            lazy[2*p]+=lazy[p];
            lazy[2*p+1]+=lazy[p];
        }
        lazy[p]=0; // we already propagated it, so it may be set to 0 now
    }
}

//function to update the segment tree (change an entire interval into a number)
void update(int p, int l, int r, int a, int b, long long x){
    push(p, l, r);
    if(l>b or r<a) return; // out of bounds

    //in case the interval we're looking at is contained in the interval that's being wanted to be changed
    if(l>=a and r<=b){
        st[p]+=x*(r-l+1);
        if(l!=r){
            lazy[2*p] += x;
            lazy[2*p+1] += x;
        }
        return;
    }
    int mid = (l+r)>>1; // same as (l+r)/2
    update(2*p, l, mid, a, b, x);
    update(2*p+1, mid+1, r, a, b, x);
    st[p] = st[2*p] + st[2*p+1];
}

//function that searches for and returns the sum of all elements in an interval
long long query(int p, int l, int r, int a, int b){
    push(p, l, r);
    if(l>b or r<a) return 0; // out of bounds
    if(l>=a and r<=b) return st[p];
    int mid = (l+r)>>1;
    return query(2*p, l, mid, a, b) + query(2*p+1, mid+1, r, a, b);
}
