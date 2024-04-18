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

int inf = 2e9;

int main() {
	// usaco();
	int k, n, m;
	int a, b;
	scd(k);
	scd(n);
	scd(m);
	scd(a);
	scd(b);

	vi val(k+1);

	frange(i, k) scd(val[i+1]);

	vi sch(n+1);
	forr(i, 1, n+1) scd(sch[i]);
	vi pln(m+1);
	forr(i, 1, m+1) scd(pln[i]);

	vector<vi> dp(4, vi(m+1, -inf)), pre(4, vi(m+1, -inf));
	pre[0][0] = 0;
	pre[1][0] = pre[2][0] = a;

	// forr(i, 1, n+1) {
	// 	dp[0][i][0] = 0;
	// 	dp[1][i][0] = a + b * i;
	// 	dp[3][i][0] = 2*a + b * i;
	// }

	forr(i, 1, m+1) {
		pre[2][i] = a + b * i;
		// pre[3][i] = 2*a + b *i;
	}

	// pre[3][0] = 2*a;
	int ma = -inf;
	forr(i, 1, n+1) {
		dp[0][0] = 0;
		dp[1][0] = a;
		dp[2][0] = a;

		// forr(i, 1, n+1) {
		// 	dp[0][i][0] = 0;
		// 	dp[1][i][0] = a + b * i;
		// 	dp[3][i][0] = 2*a + b * i;
		// }

		// forr(i, 1, m+1) {
		// 	pre[2][i] = max(pre[2][i], a + b * i);
		// 	// pre[3][i] = max(pre[3][i], 2*a + b *i);
		// }
		forr(j, 1, m+1) {
			if(sch[i] == pln[j]) {
				frange(k, 3)
					dp[0][j] = max(dp[0][j], pre[k][j-1] + val[sch[i]]);
					// ma = max(ma, dp[0][i][j]);
			}
			
			// dp[3][j] = pre[3][j-1] + 2*b;
			// dp[3][j] = max(dp[3][j], pre[2][j-1] + a + 2*b);
			// dp[3][j] = max(dp[3][j], pre[1][j-1] + a + 2*b);
			// dp[3][j] = max(dp[3][j], pre[0][j-1] + 2*a + 2*b);

			dp[1][j] = pre[1][j] + b;
			frange(k, 3) dp[1][j] = max(dp[1][j], pre[k][j] + a + b);
			dp[2][j] = dp[2][j-1] + b;
			frange(k, 3) dp[2][j] = max(dp[2][j], dp[k][j-1] + a + b);
		}
		pre = dp;
		frange(k, 3)
		ma = max(ma,dp[k][m]);
		dp = vector<vi>(4, vi(m+1, -inf));
	}

	// frange(i, n+1) {
	// 	ma = max({ma, dp[0][i][m], dp[1][i][m], dp[2][i][m], dp[3][i][m]});
	// }


	printf("%d", ma);

}