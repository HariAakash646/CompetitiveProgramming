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

lli inf = 1e18;

int main() {
	// usaco();
	int n;
	string str;
	cin >> n >> str;

	vi rv, gv, yv;
	rv.pb(0);
	gv.pb(0);
	yv.pb(0);
	int rc = 0, gc = 0, yc = 0;
	vi prr(n+1), prg(n+1), pry(n+1);

	str = ' ' + str;

	forr(i, 1, n+1) {
		prr[i] = prr[i-1];
		prg[i] = prg[i-1];
		pry[i] = pry[i-1];
		if(str[i] == 'R') {
			rc++;
			prr[i]++;
			rv.pb(i);
		}
		else if(str[i] == 'G') {
			gc++;
			prg[i]++;
			gv.pb(i);
		}
		else {
			yc++;
			pry[i]++;
			yv.pb(i);
		}
	}

	vector<vector<vvi>> dp(3, vector<vvi>(rc+1, vvi(gc+1, vi(yc+1, 2e9))));

	dp[0][0][0][0] = dp[1][0][0][0] = dp[2][0][0][0] = 0;

	forr(i, 0, rc+1) {
		forr(j, 0, gc+1) {
			forr(k, 0, yc+1) {
				if(i + j + k == 0) continue;
				frange(c, 3) {
					int v = 2e9;
					if(c == 0 && i > 0) {
						int tot = min(dp[1][i-1][j][k], dp[2][i-1][j][k]);
						tot += max(0, prg[rv[i]] - prg[gv[j]]) + max(0, pry[rv[i]] - pry[yv[k]]);
						v = min(v, tot);
					}
					if(c == 1 && j > 0) {
						int tot = min(dp[0][i][j-1][k], dp[2][i][j-1][k]);
						tot += max(0, prr[gv[j]] - prr[rv[i]]) + max(0, pry[gv[j]] - pry[yv[k]]);
						v = min(v, tot);
					}
					if(c == 2 && k > 0) {
						int tot = min(dp[0][i][j][k-1], dp[1][i][j][k-1]);
						tot += max(0, prr[yv[k]] - prr[rv[i]]) + max(0, prg[yv[k]] - prg[gv[j]]);
						v = min(v, tot);
					}
					dp[c][i][j][k] = v;
					// printf("%d ", v);
				}
			}
		}
	}
	int mi = 2e9;
	frange(i, 3) mi = min(mi, dp[i][rc][gc][yc]);
	if(mi < 2e9)
	printf("%d", mi);
	else printf("-1");
}