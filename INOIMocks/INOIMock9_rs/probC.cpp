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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int findf(int x, vi &disset) {
	if(x == disset[x]) return x;
	disset[x] = findf(disset[x], disset);
	return disset[x];
}

void unionf(int x, int y, vi &disset, vi &sze) {
	x = findf(x, disset);
	y = findf(y, disset);
	if(sze[x] < sze[y]) swap(x, y);
	disset[y] = x;
	sze[x] = max(sze[x], sze[y]+1);
}

int main() {
	// usaco();
	int n, m, k;
	scd(n);
	scd(m);
	scd(k);

	vector<pair<pair<lli, int>, pii>> edg(m);

	frange(i, m) {
		scd(edg[i].s.f);
		scd(edg[i].s.s);
		sclld(edg[i].f.f);
		edg[i].f.s = i;
	}

	sort(all(edg), greater<>());
	vi out(m);
	vvi disset(k+1, vi(n+1));
	forr(i, 1, k+1) {
		forr(j, 1, n+1) disset[i][j] = j;
	}
	vvi sze(k+1, vi(n+1));
	for(auto p : edg) {
		int lo = 1;
		int hi = k;

		while(lo != hi) {
			int mid = (lo+hi)/2;
			if(findf(p.s.f, disset[mid]) != findf(p.s.s, disset[mid])) {
				hi = mid;
			}
			else lo = mid+1;
		}
		if(findf(p.s.f, disset[lo]) != findf(p.s.s, disset[lo])) {
			out[p.f.s] = lo;
			unionf(p.s.f, p.s.s, disset[lo], sze[lo]);
		}
	}

	frange(i, m) printf("%d\n", out[i]);
}