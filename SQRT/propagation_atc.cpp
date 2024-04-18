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

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
	// usaco();
	int n, m, q;
	scd(n);
	scd(m);
	scd(q);
	vvi graph(n+1), grsq(n+1);
	vi deg(n+1);
	frange(i, m) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(b);
		graph[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	int sq = 500;
	forr(i, 1, n+1) {
		for(auto e : graph[i]) {
			if(deg[e] >= sq) {
				grsq[i].pb(e);
			}
		}
	}

	vii vec(n+1);
	vii upd(n+1);
	forr(i, 1, n+1) vec[i] = mp(0, i);
	forr(i, 1, n+1) upd[i] = mp(-1, 0);

	forr(i, 1, q+1) {
		int x;
		scd(x);
		pii p = vec[x];
		for(auto e : grsq[x]) {
			p = max(upd[e], p);
		}
		vec[x] = mp(i, p.s);
		if(deg[x] < sq) {
			for(auto e : graph[x]) {
				vec[e] = vec[x];
			}
		}
		else upd[x] = vec[x];
	}

	forr(x, 1, n+1) {
		pii p = vec[x];
		for(auto e : grsq[x]) {
			p = max(upd[e], p);
		}
		vec[x] = p;
		printf("%d ", vec[x].s);
	}
}