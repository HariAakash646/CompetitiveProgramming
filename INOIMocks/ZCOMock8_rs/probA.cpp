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
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

const lli mod = 1e9 + 7;

int main() {
	// usaco();
	int n, m, k;
	scd(n);
	scd(m);
	scd(k);

	vvi graph(n+1);
	frange(i, k) {
		int a, b;
		scd(a);
		scd(b);
		graph[b].pb(a);
		// graph[b].pb(a);
	}

	vector<vll> dp(m+1, vll(n+1));
	lli pre = 0;
	forr(i, 1, n+1) {
		dp[1][i] = 1;
		pre++;
	}

	forr(i, 2, m+1) {
		lli tot = 0;
		forr(j, 1, n+1) {
			dp[i][j] = pre;
			for(auto e : graph[j]) {
				dp[i][j] -= dp[i-1][e];
				dp[i][j] += mod;
				dp[i][j] %= mod;
			}
			// printf("%lld ", dp[i][j]);
			tot += dp[i][j];
			tot %= mod;
		}
		// printf("\n");
		pre = tot;
	}
	printf("%lld", pre);
}