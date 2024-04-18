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

vi disset, sze;
int c = 0;

int findf(int x) {
	int u = x;
	while(disset[x] != x) {
		x = disset[x];
	}
	disset[u] = x;
	return x;
}

void unionf(int x, int y) {
	x = findf(x);
	y = findf(y);
	if(x == y) return;
	if(sze[y] > sze[x]) swap(x, y);
	disset[y] = x;
	sze[x] = max(sze[x], sze[y]+1);
	c--;
}

int main() {
	// usaco();
	int n;
	scd(n);

	vector<pii> v2;

	frange(i, n) {
		int h;
		scd(h);
		v2.pb(mp(h, i));
	}
	sort(all(v2), greater<>());

	disset = vi(n, -1);
	sze = vi(n, 1);
	int ma = 0;
	frange(i, n) {
		auto p = v2[i];
		int e = p.s;
		
		disset[e] = e;
		c++;
		if(e < n-1 && disset[e+1] != -1) unionf(e, e+1);
		if(e > 0 && disset[e-1] != -1) unionf(e, e-1);
		if(i == n-1 || v2[i+1].f != p.f)
			ma = max(ma, c);
	}
	printf("%d", ma);
}