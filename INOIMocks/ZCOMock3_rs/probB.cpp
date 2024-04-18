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

const lli mod = 1e9 + 7;

int main() {
	// usaco();
	int n;
	scd(n);

	vi vec(n);
	frange(i, n) scd(vec[i]);

	vll dp1(n);
	vector<vll> dp2(30, vll(n));

	dp1[0] = 1;
	frange(i, 30) {
		if((vec[0] & (1<<i))) dp2[i][0] = 1;
	}

	forr(i, 1, n) {
		frange(j, 30) {
			if(vec[i] & (1<<j)) dp1[i] += dp2[j][i-1];
		}
		dp1[i] %= mod;
		frange(j, 30) {
			dp2[j][i] = dp2[j][i-1];
			if(vec[i] & (1<<j)) dp2[j][i] += dp1[i];
			dp2[j][i] %= mod;
		}
	}

	printf("%lld", dp1[n-1]);
}