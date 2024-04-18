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
	int n, q;
	scd(n);
	scd(q);
	lli d, a, b;
	sclld(d);
	sclld(a);
	sclld(b);

	lli ma = 1e12;

	vi vec(1e6+1);

	frange(i, n) {
		lli l, r;
		sclld(l);
		sclld(r);
		
		forr(i, l, r+1) vec[i] = 1;
	}

	vll dp(1e6+1, 1e18);
	dp[0] = 0;
	forr(i, 1, 1e6+1) {
		if(vec[i]) continue;
		if(dp[i-1] != 1e18) dp[i] = dp[i-1] + a;
		if(i - d >= 0) dp[i] = min(dp[i], dp[i-d] + b);
	}

	frange(_, q) {
		lli x;
		sclld(x);
		if(dp[x] == 1e18) printf("-1\n");
		else printf("%lld\n", dp[x]);
	}
}