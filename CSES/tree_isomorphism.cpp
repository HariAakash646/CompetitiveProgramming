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

const lli mod = 1e9 + 9;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const lli p = uniform_int_distribution<lli>(1, mod - 1)(rng);

vvi graph;
vll dp;

lli dfs(int x, int pa, int d) {
	lli v = 1;
	lli c = 1;
	for(auto e : graph[x]) {
		if(e != pa) {
			v += p*dfs(e, x, d+1)%mod;
			v %= mod;
			c++;
		}
	}
	dp[x] = v;
	// v *= c;
	// v %= mod;
	// v *= p;
	// v %= mod;
	// v = (d*v) % mod;
	// printf("%d %lld\n", x, v);
	return v;
}

int main() {
	// usaco();
	int t;
	scd(t);

	frange(_, t) {
		int n;
		scd(n);

		graph = vvi(n+1);

		frange(i, n-1) {
			int a, b;
			scd(a);
			scd(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}

		dp = vll(n+1);
		lli v1 = dfs(1, 0, 1);

		multiset<lli> st1, st2;
		forr(i, 1, n+1) st1.insert(dp[i]);

		graph = vvi(n+1);

		frange(i, n-1) {
			int a, b;
			scd(a);
			scd(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}

		dp = vll(n+1);
		lli v2 = dfs(1, 0, 1);

		forr(i, 1, n+1) st2.insert(dp[i]);

		for(auto e : st2) {
			auto it = st1.find(e);
			if(it != st1.end()) st1.erase(it);
		}

		// printf("%lld %lld ", v1, v2);

		if(!st1.size()) printf("YES\n");
		else printf("NO\n");
	}

}