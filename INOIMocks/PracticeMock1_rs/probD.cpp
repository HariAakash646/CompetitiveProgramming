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
	// freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
}

int main() {
	usaco();
	int c, t;
	scd(c);
	scd(t);

	frange(_, t) {
		int n, m, k;
		lli d;
		scd(n);
		scd(m);
		scd(k);
		sclld(d);

		// vll dp(k+1, -1e17), pre(k+1, -1e17);
		vector<pair<pii, lli>> vec(m+1);

		forr(i, 1, m+1) {
			scd(vec[i].f.f);
			scd(vec[i].f.s);
			sclld(vec[i].s);
		}
		sort(all(vec));
		// pre[0] = 0;

		vll dp(m+1);
		dp[0] = 0;

		forr(i, 1, m+1) {
			dp[i] = dp[i-1];
			if(vec[i].f.s <= k) dp[i] += max(0LL, vec[i].s - d * vec[i].f.s);
		}

		// forr(i, 1, m+1) {
		// 	dp[0] = *max_element(all(pre));
		// 	lli ma = dp[0];
		// 	forr(j, 1, k+1) {
		// 		if(j-(vec[i].f.f-vec[i-1].f.f) >= 0)
		// 			dp[j] = pre[j-(vec[i].f.f-vec[i-1].f.f)] - d * (vec[i].f.f-vec[i-1].f.f);
		// 		else dp[j] = ma - d * j;
		// 		if(j >= vec[i].f.s) dp[j] += vec[i].s;
		// 	}
		// 	pre = dp;
		// }
		printf("%lld\n", dp[m]);

	}
}