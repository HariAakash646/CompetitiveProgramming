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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const lli mod = 1e9+7;

int n, q;

vi grid;

const int MAXN = 3e4 + 10;

lli dp[MAXN][8] = {0};

lli solve(int l, int r) {
	// vector<vll> dp(8, vll(8));

	forr(i, l-1, r+1) {
		frange(j, 8) dp[i][j] = 0;
	}

	dp[l-1][7] = 1;
	forr(i, l, r+1) {
		vll val(8);
		frange(j, 8) {
			val[0] += dp[i-1][j];
			val[3] += dp[i-1][j];
			val[6] += dp[i-1][j];
			frange(k, 3) {
				if((j & (1<<k)) == 0) {
					val[1<<k] += dp[i-1][j];
				}
			}
		}
		val[7] = 3*dp[i-1][0] + dp[i-1][1] + dp[i-1][4] + 2 * dp[i-1][2] + dp[i-1][3] + dp[i-1][6];
		val[3] += dp[i-1][0] + dp[i-1][4];
		val[6] += dp[i-1][0] + dp[i-1][1];
		val[5] = dp[i-1][0] + dp[i-1][2];
		frange(j, 8) val[j] %= mod;

		frange(j, 8) {
			if((j | grid[i]) == j) {
				dp[i][j] = val[j^grid[i]];
			}
		}
	}
	lli tot = 0;
	frange(i, 8) tot += dp[r][i];
	tot %= mod;
	return tot;
}

int main() {
	// usaco();
	fastio();
	cin >> n >> q;

	grid = vi(n+1);
	frange(i, 3) {
		string str;
		cin >> str;
		forr(j, 1, n+1) {
			if(str[j-1] == 'x')
				grid[j] += (1<<i);
		}
	}

	forr(i, 0, n+1) {
		frange(j, 8) dp[i][j] = 0;
	}

	dp[0][7] = 1;
	forr(i, 1, n+1) {
		vll val(8);
		frange(j, 8) {
			val[0] += dp[i-1][j];
			val[3] += dp[i-1][j];
			val[6] += dp[i-1][j];
			frange(k, 3) {
				if((j & (1<<k)) == 0) {
					val[1<<k] += dp[i-1][j];
				}
			}
		}
		val[7] = 3*dp[i-1][0] + dp[i-1][1] + dp[i-1][4] + 2 * dp[i-1][2] + dp[i-1][3] + dp[i-1][6];
		val[3] += dp[i-1][0] + dp[i-1][4];
		val[6] += dp[i-1][0] + dp[i-1][1];
		val[5] = dp[i-1][0] + dp[i-1][2];
		frange(j, 8) val[j] %= mod;

		frange(j, 8) {
			if((j | grid[i]) == j) {
				dp[i][j] = val[j^grid[i]];
			}
		}
	}

	frange(_, q) {
		int t;
		cin >> t;
		if(t == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			grid[y] = grid[y] ^ (1<<x);
		}
		else {
			int l,r;
			cin>>l>>r;
			int ln = r - l+1;
			lli tot = 0;
			frange(i, 8) tot += dp[ln][i];
			tot %= mod;
			cout << tot << "\n";
		}
	}
}