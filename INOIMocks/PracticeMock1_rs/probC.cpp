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
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int c, n, m, q;
vi v1, v2;

void solve() {
	vi vt1 = v1;
	vi vt2 = v2;
	if(vt1[0] == vt2[0]) {
		printf("0");
		return;
	}
	if(vt1[0] > vt2[0]) swap(vt1, vt2);
	int n = vt1.size();
	int m = vt2.size();
	vector<vb> dp(n, vb(m));
	dp[0][0] = true;

	forr(i, 1, n) {
		if(vt1[i] < vt2[0]) dp[i][0] = dp[i-1][0];
	}

	forr(i, 1, m) {
		if(vt1[0] < vt2[i]) dp[0][i] = dp[0][i-1];
	}

	forr(i, 1, n) {
		forr(j, 1, m) {
			if(vt1[i] < vt2[j]) dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
		}
	}
	if(dp[n-1][m-1]) printf("1");
	else printf("0");
}

int main() {
	usaco();
	
	scd(c);
	scd(n);
	scd(m);
	scd(q);
	
	v1 = vi(n);
	v2 = vi(m);
	frange(i, n) scd(v1[i]);
	frange(i, m) scd(v2[i]);

	solve();

	frange(_, q) {
		int kx, ky;
		scd(kx);
		scd(ky);
		vi og1 = v1;
		vi og2 = v2;
		frange(i, kx) {
			int id, v;
			scd(id);
			scd(v);
			id--;
			v1[id] = v;
		}
		frange(i, ky) {
			int id, v;
			scd(id);
			scd(v);
			id--;
			v2[id] = v;
		}
		solve();
		v1 = og1;
		v2 = og2;
	}
}