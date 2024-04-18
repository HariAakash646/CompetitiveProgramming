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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, m, b;
	scd(n);
	scd(m);
	scd(b);

	vector<vii> graph(n+1);
	vii edg(m+1);

	forr(i, 1, m+1) {
		int a, b;
		scd(a);
		scd(b);
		graph[a].pb(mp(b, i));
		graph[b].pb(mp(a, i));
		edg[i] = mp(a, b);
	}

	vb vis(n+1);
	vi exl(n+1);
	priority_queue<pii> q;

	frange(i, b) {
		int x, y;
		scd(x);
		scd(y);
		q.push(mp(y, x));
		// q.push(mp(y-1, edg[x].s));
	}

	while(q.size()) {
		auto p = q.top();
		q.pop();
		if(vis[p.s]) continue;
		vis[p.s] = true;
		if(p.f==0) continue;
		exl[p.s] = true;
		for(auto e : graph[p.s]) {
			// exl[e.s] = true;
			q.push(mp(p.f-1, e.f));
		}
	}
	int c = 0;
	forr(i, 1, n+1) {
		if(exl[i]) c++;
	}
	printf("%d", c);
}