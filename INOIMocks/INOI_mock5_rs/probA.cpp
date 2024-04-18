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

int n, k;
vll vec;
vll dp;
vll pre;

vector<vll> mav, miv;

void init() {
	mav = miv = vector<vll>(20, vll(n+1));
	frange(i, n+1) {
		mav[0][i] = miv[0][i] = vec[i];
	}

	forr(i, 1, 20) {
		frange(j, n+1) {
			mav[i][j] = max(mav[i-1][j], mav[i-1][min(n, j+(1<<(i-1)))]);
			miv[i][j] = min(miv[i-1][j], miv[i-1][min(n, j+(1<<(i-1)))]);
		}
	}
}

lli query_ma(int l, int r) {
	int ln = r - l + 1;
	int msb = 31 - __builtin_clz(ln);
	return max(mav[msb][l], mav[msb][r-(1<<msb)+1]);
}

lli query_mi(int l, int r) {
	int ln = r - l + 1;
	int msb = 31 - __builtin_clz(ln);
	return min(miv[msb][l], miv[msb][r-(1<<msb)+1]);
}

void dnc(int l, int r, int lx, int rx) {
	if(l > r) return;
	int mid = (l+r)/2;
	pair<lli, int> opt = mp(-1e18, 0);
	for(int i=lx; i<=min(rx, mid); i++) {
		opt = max(opt, mp(pre[i-1]+query_ma(i, mid)-query_mi(i, mid), i));
	}
	dp[mid] = opt.f;

	if(l < mid) dnc(l, mid-1, lx, opt.s);
	if(mid < r) dnc(mid+1, r, opt.s, rx);

}

int main() {
	// usaco();
	
	scd(n);
	scd(k);

	vec = vll(n+1);

	forr(i, 1, n+1) sclld(vec[i]);

	dp = pre = vll(n+1, -1e17);
	pre[0] = 0;

	// forr(i, 1, k+1) {
	// 	// lli ma = -1e17;
	// 	forr(j, 1, n+1) {
	// 		lli ma = -1e18;
	// 		lli mv = vec[j];
	// 		lli miv = vec[j];
	// 		for(int k=j-1; k>=0; k--) {
	// 			ma = max(ma, dp[i-1][k] + mv - miv);
	// 			miv = min(miv, vec[k]);
	// 			mv = max(mv, vec[k]);
	// 		}
	// 		dp[i][j] = ma;
	// 	}
	// }
	init();
	forr(i, 1, k+1) {
		dnc(1, n, 1, n);
		pre = dp;
	}
	printf("%lld", dp[n]);
}