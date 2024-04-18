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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int n;
lli k;

vector<vector<pair<int, lli>>> graph;
vll dp;
vi outv;

int c = 0;

pair<lli, lli> dfs(int x, int p) {
	pair<lli, lli> out = {-1, 0};
	for(auto e : graph[x]) {
		if(e.f != p) {
			auto val = dfs(e.f, x);
			if(val.f > 0)  {
				if(val.f + e.s <= k) {
					if(out.f == -1) out.f = val.f + e.s;
					out.f = min(out.f, val.f + e.s);
				}
			}
			if(val.s >= 0) {
				if(val.s + e.s > k) {
					c++;
					outv.pb(e.f);
					if(out.f == -1) out.f = e.s;
					out.f = min(out.f, e.s);
				}
				else {
					out.s = max(out.s, val.s+e.s);
				}
			}
		}
	}
	if(out.f > -1) {
		if(out.f + out.s <= k) out.s = -1;
	}
	return out;
}

int main() {
	// usaco();
	scd(n);
	sclld(k);

	graph = vector<vector<pair<int, lli>>>(n+1);

	frange(i, n-1) {
		int a, b;
		lli v;
		scd(a);
		scd(b);
		sclld(v);
		graph[a].pb(mp(b, v));
		graph[b].pb(mp(a, v));
	}

	auto p = dfs(1, 0);
	if(p.s >= 0) {c++; outv.pb(1);}
	printf("%d\n", c);
	for(auto e : outv) printf("%d ", e);
}