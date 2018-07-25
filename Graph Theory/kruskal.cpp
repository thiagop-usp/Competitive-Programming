#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define inf 0x3f3f3f3f
#define PI acos(-1);
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define ll long long

const int MAXN = 1e5+5;

tuple<int, int, int> edges[MAXN]; 	// this tuple is formed by 3 ints: <weight of the edge between u and v; vertice u; vertice v>
int dad[MAXN]; 				// parent of each node

int Find(int x){
	if(x==dad[x]) return x; 		// if that node is the root of the tree (it's the pivot of the subset it's in)
	return x = Find(dad[x]);		// keep climbing the tree to find its root
}

void Union(int x, int y){
	x = Find(x); 				// find pivot of the subset x's in
	y = Find(y);				// find pivot of the subset y's in
	if(x!=y) dad[x] = y; 			// if the pivots found are different, then make the Union
}

ll kruskal(int m){
	ll cost = 0;
	for (int i = 0; i < m; ++i)
	{
		int w = get<0>(edges[i]); 	// weight of the edge between u and v
		int u = get<1>(edges[i]); 	// vertice u
		int v = get<2>(edges[i]); 	// vertice v
		if(Find(u)!=Find(v)){     	// if they have different pivots, i.e., if connecting u and v won't form a cycle
			Union(u, v);          	// make the union
			cost+=w;  		// add the cost to the total
		}
	}
	return cost;				// returns the total weight of the Minimum Spanning Tree
}

int main(){
	fastcin;
	int n, m;
	cin >> n >> m; 

	// n = number of vertices
	// m = number of edges

	for(int i = 0; i <n ; i++) dad[i] = i;	// in the beginning, the parents of every node is the node itself

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;					
		edges[i] = make_tuple(w, u, v);
	}

	sort(edges, edges+m);	// sorting weights increasingly, since kruskal is a greedy algorithm and will add the m lightest edges

	cout << kruskal(m) << endl;

	return 0;
}
