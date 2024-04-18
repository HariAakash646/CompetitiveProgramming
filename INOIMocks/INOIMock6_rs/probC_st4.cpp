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
	int n;
	lli k;
	scd(n);
	sclld(k);

	vi vec(n);

	frange(i, n) scd(vec[i]);

	vi pwd(n);
	frange(i, n) scd(pwd[i]);

	lli out = 0;

	frange(i, n) {
		if(vec[i] <= pwd[i]) {
			vec[i] = pwd[i] - vec[i];
		}
		else {
			vec[i] = k - vec[i] + 1 + pwd[i];
		}
	}

	k++;

	vector<vll> dp(n, vll(n, 1e18));
	vector<vll> val(n, vll(n));

	frange(i, n) {
		dp[0][i] = vec[0] + i*k;
		val[0][i] = vec[0] + i*k;
	}

	forr(i, 1, n) {
		vll mvc(n);
		lli mi = dp[i-1][0] - val[i-1][0];
		frange(j, n) {
			mi = min(mi, dp[i-1][j] - val[i-1][j]);
			mvc[j] = mi;
		}
		mi = 1e18;
		vll mac(n);
		for(int j=n-1; j>=0; j--) {
			mi = min(mi, dp[i-1][j]);
			mac[j] = mi;
		}
		frange(j, n) {
			lli v = vec[i] + j*k; 
			val[i][j] = v;
			int id = lower_bound(all(val[i-1]), v) - val[i-1].begin();
			if(id < n) {
				dp[i][j] = dp[i-1][id];
			}
			if(id > 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][id-1] + v - val[i-1][id-1]);
			}
			// dp[i][j] = 1e18;
			// frange(l, n) {
			// 	lli v1 = vec[i-1] + l*k;
			// 	if(v1 >= v) dp[i][j] = min(dp[i][j], dp[i-1][l]);
			// 	else dp[i][j] = min(dp[i][j], dp[i-1][l] + v - v1);
			// }
			// printf("%lld ", dp[i][j]);
		}
		// printf("\n");
	}
	lli mi = 1e18;
	for(auto p : dp[n-1]) mi = min(mi, p);
	printf("%lld", mi);
}