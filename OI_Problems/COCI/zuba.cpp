#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
	// usaco();
	int n, k;
	scd(n);
	scd(k);
	vector<vvi> dp(n+1, vvi(n+1, vi(k, 0)));
	vi vec(n);
	frange(i, n) scd(vec[i]);

	frange(i, n) {
		frange(j, k) {
			dp[i][i][j] = k - j - 1;
		}
	}

	forr(i, 1, n) {
		for(int j=0; j+i<n; j++) {
			for(int l=k-1; l>=0; l--) {
				int i2 = j+i;
				int v = vec[j];
				// dp[j][i2][l] = dp[j+1][i2][l] + k - l - 1;
				dp[j][i2][l] = 1e9;
				if(l < k-1) {
					dp[j][i2][l] = dp[j][i2][l+1] + 1;
				}
				else {
					dp[j][i2][l] = dp[j+1][i2][0];
				}
				forr(r, j+1, i2+1) {
					if(vec[j] == vec[r])
						dp[j][i2][l] = min(dp[j][i2][l], dp[j+1][r-1][0] + dp[r][i2][min(k-1,l+1)]);
				}
				// dp[j][i2][l] += l;
			}
		}
	}
	printf("%d", dp[0][n-1][0]);
}