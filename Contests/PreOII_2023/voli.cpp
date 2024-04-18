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

struct Edge {
	int d;
	int c;
	lli l;
};

long long plan(int n, int m, int k, vector<int> A, vector<int> B, vector<int> L, vector<int> C, vector<int> T) {
	vector<vector<Edge>> graph(n);
	vector<map<int, vii>> gr2(n);
	frange(i, m) {
		int a = A[i];
		int b = B[i];
		int c = C[i];
		lli l = L[i];
		Edge tmp;
		tmp.d = b;
		tmp.c = c;
		tmp.l = l;
		graph[a].pb(tmp);
		tmp.d = a;
		graph[b].pb(tmp);
		gr2[a][c].pb(mp(b, l));
		gr2[b][c].pb(mp(a, l));
	}

	priority_queue<pair<lli, pii>> pq;
	vector<map<int, lli>> dist(n);
	vector<map<int, bool>> vis(n);

	dist[0][-1] = 0;
	pq.push(mp(0, mp(0, -1)));

	while(pq.size()) {
		auto p = pq.top();
		pq.pop();
		if(vis[p.s.f][p.s.s]) continue;
		vis[p.s.f][p.s.s] = true;

		if(p.s.s != -1) {
			for(auto e : gr2[p.s.f][p.s.s]) {
				if(dist[e.f].find(p.s.s) == dist[e.f].end() || -p.f + e.s < dist[e.f][p.s.s]) {
					lli v = -p.f + e.s;
					dist[e.f][p.s.s] = v;
					pq.push(mp(-v, mp(e.f, p.s.s)));
					if(dist[e.f].find(-1) == dist[e.f].end() || v < dist[e.f][-1]) {
						dist[e.f][-1] = v;
						pq.push(mp(-v, mp(e.f, -1)));
					}
				}
			}
			continue;
		}

		for(auto e : graph[p.s.f]) {
			lli t = T[e.c];

			if(dist[e.d].find(e.c) == dist[e.d].end() || -p.f + e.l + t < dist[e.d][e.c]) {
				lli v = -p.f + e.l + t;
				dist[e.d][e.c] = v;
				pq.push(mp(-v, mp(e.d, e.c)));
				if(dist[e.d].find(-1) == dist[e.d].end() || v < dist[e.d][-1]) {
					dist[e.d][-1] = v;
					pq.push(mp(-v, mp(e.d, -1)));
				}
			}

		}
	}
	lli mi = 1e18;
	for(auto p : dist[n-1]) {
		mi = min(mi, p.s);
	}

	return mi;

}