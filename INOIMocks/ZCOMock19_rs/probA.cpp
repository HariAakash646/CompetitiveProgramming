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

int n, k;
vll dp, pre;

vector<vll> miv, mav;

void init(vll vec) {
	miv = mav = vector<vll>(20, vll(n));
	frange(i, n) miv[0][i] = mav[0][i] = vec[i];

	forr(i, 1, 20) {
		frange(j, n) {
			miv[i][j] = min(miv[i-1][j], miv[i-1][min(n-1, j+(1<<(i-1)))]);
			mav[i][j] = max(mav[i-1][j], mav[i-1][min(n-1, j+(1<<(i-1)))]);
		}
	}
}

lli query(int l, int r) {
	int ln = r - l + 1;
	int id = 31 - __builtin_clz(ln);
	lli ma = max(mav[id][l], mav[id][max(0, r-(1<<id)+1)]);
	lli mi = min(miv[id][l], miv[id][max(0, r-(1<<id)+1)]);
	return ma - mi;
}

void rec(int x, int l, int r, int lx, int rx) {
	int mid = (l+r)/2;
	int opt = lx;

	for(int i=lx; i<=min(rx, mid-1); i++) {
		lli v = pre[i] + query(i, mid-1);
		if(v > dp[mid]) {
			dp[mid] = v;
			opt = i;
		}
	}

	if(l <= mid-1) rec(x, l, mid-1, lx, opt);
	if(r >= mid+1) rec(x, mid+1, r, opt, rx);
}

int main() {
	// usaco();
	scd(n);
	scd(k);

	pre = dp = vll(n+1, -1e16);

	vll vec(n);
	frange(i, n) sclld(vec[i]);

	pre[0] = 0;
	init(vec);


	forr(i, 1, k+1) {
		rec(i, 1, n, 0, n-1);
		pre = dp;
		dp = vll(n+1, -1e16);
	}

	printf("%lld", pre[n]);
}