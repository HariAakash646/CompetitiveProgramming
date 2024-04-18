#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
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
	int n, m;
	scd(n);
	scd(m);

	vector<vii> graph(n);

	frange(i, m) {
		int a, b;
		scd(a);
		scd(b);
		int v;
		scd(v);
		graph[a].pb(mp(b, v));
		graph[b].pb(mp(a, v));
	}

	queue<pair<pii, int>> q;
	q.push(mp(mp(0, 0), 0));
	q.push(mp(mp(0, 1), 0));
	vector<vb> vis(2, vb(n));

	while(q.size()) {
		auto p = q.front();
		q.pop();
		if(vis[p.f.s][p.f.f]) continue;
		if(p.f.f == n-1) {
			printf("%d", p.s);
			return 0;
		}
		vis[p.f.s][p.f.f] = true;
		for(auto e : graph[p.f.f]) {
			if(e.s == p.f.s) {
				q.push(mp(mp(e.f, !p.f.s), p.s+1));
			}
		}
	}
	printf("-1");

}