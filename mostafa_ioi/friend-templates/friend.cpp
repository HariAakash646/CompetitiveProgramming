#include "friend.h"
#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vvi graph;
vi val;

pii dfs(int x, int p) {
	int v1 = val[x];
	int v2 = 0;

	for(auto e : graph[x]) {
		if(e != p) {
			auto out = dfs(e, x);
			v1 += out.s;
			v2 += max(out.f, out.s);
		}
	}
	return mp(v1, v2);
}

vi pos;

int findf(int x) {
	if(x == pos[x]) return x;
	pos[x] = findf(pos[x]);
	return pos[x];
}

int findSample(int n,int confidence[],int host[],int protocol[]){
	graph = vvi(n);
	val = vi(n);

	frange(i, n) val[i] = confidence[i];

	pos = vi(n);
	pos[0] = 0;
	int tot = 0;
	for(int i=n-1; i>=1; i--) {
		if(protocol[i] == 0) {
			val[host[i]] = max(0, val[host[i]] - val[i]);
			tot += val[i];
		}
		else if(protocol[i] == 1) {
			val[host[i]] += val[i];
		}
		else {
			val[host[i]] = max(val[host[i]], val[i]);
		}
	}

	tot += val[0];

	return tot;
}
