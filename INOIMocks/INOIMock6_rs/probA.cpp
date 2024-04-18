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

int main() {
	// usaco();
	int l, r;
	scd(l);
	scd(r);
	vvi vec(r);
	vi tot(r);
	set<pii> ran;
	frange(i, r) {
		int x;
		scd(x);

		frange(_, x) {
			int v;
			scd(v);
			vec[i].pb(v);
			tot[i] += v;
		}
		int v = l-tot[i];

		int lx = 0;
		for(auto e : vec[i]) {
			lx += e;
			int rx = lx + v - e;
			if(rx <= lx) ran.insert(mp(rx, lx));
		}
	}
	int out = 0;
	int lv = 0;
	for(auto e : ran) {
		if(e.s > lv) {
			out += e.s - max(lv, e.f);
			lv = e.s;
		}
	}
	printf("%d", out);
}