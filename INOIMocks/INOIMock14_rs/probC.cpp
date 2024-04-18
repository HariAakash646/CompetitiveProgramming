#include "navigation_lib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

vvi graph;


void Anna(int K, int n, int T, int A[], int B[]) {
	graph = vvi(n+1);
	frange(i, n-1) {
		int a = A[i];
		int b = B[i];
		graph[a].pb(b);
		graph[b].pb(a);
	}
	int id = 0;
	queue<pii> q;
	vb vis(n+1);

	q.push(mp(T, 0));

	while(q.size()) {
		auto p = q.front();
		q.pop();
		int x = p.f;
		int v = p.s;
		if(vis[x]) continue;
		vis[x] = true;

		Flag(x, v);
		
		for(auto e : graph[x]) {
			if(e > x)
				q.push(mp(e, !v));
			else q.push(mp(e, v));
		}
	}
}

void Bruno(int K, int S, int F, int L, int P[], int Q[]) {
	
	int out = S;
	frange(i, L) {
		if(P[i] > S && Q[i] == F) out = P[i];
		if(P[i] < S && Q[i] != F) out = P[i];
	}
	Answer(out);
} 