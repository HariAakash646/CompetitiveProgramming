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

int ma = 1;
vi disset, sze;

int findf(int x) {
	if(disset[x] == x) return x;
	disset[x] = findf(disset[x]);
	return disset[x];
}

void unionf(int x, int y) {
	x = findf(x);
	y = findf(y);
	if(x == y) return;
	disset[y] = x;
	sze[x] += sze[y];
	ma = max(ma, sze[x]);
}

int main() {
	// usaco();
	int n, m, q;
	scd(n);
	scd(m);
	scd(q);

	disset = sze = vi(n+1, 1);

	forr(i, 1, n+1) disset[i] = i;

	vector<pair<lli,  pii>> edg(m);

	frange(i, m) {
		scd(edg[i].s.f);
		scd(edg[i].s.s);
		sclld(edg[i].f);
	}

	sort(all(edg), greater<>());
	vll val(n+1, -1);
	int curr = 1;

	for(auto p : edg) {
		unionf(p.s.f, p.s.s);
		for(int i=curr+1; i<=ma; i++) {
			val[i] = p.f;
		}
		curr = ma;
	}

	frange(_, q) {
		int v;
		scd(v);
		printf("%lld\n", val[v]);
	}


}