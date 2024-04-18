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
typedef long long lli;
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
// const lli p = uniform_int_distribution<lli>(1, mod - 1)(rng);

vll hsh;
vvi graph;
vll dp;

lli dfs(int x, int pa, int d) {
	lli v = 1;
	lli c = 1;
	for(auto e : graph[x]) {
		if(e != pa) {
			v *= (hsh[d] * dfs(e, x, d+1))%mod;
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

vi sze;

void dfs2(int x, int p) {
	for(auto e : graph[x]) {
		if(e != p) {
			dfs2(e, x);
			sze[x] += sze[e];
		}
	}
} 

int cent(int x, int p, int n) {
	for(auto e : graph[x]) {
		if(e != p) {
			if(sze[e] > n/2) {
				return cent(e, x, n);
			}
		}
	}
	return x;
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

		hsh = vll(n+1);

		forr(i, 1, n+1) {
			hsh[i] = uniform_int_distribution<lli>(1, mod - 1)(rng);
		}

		sze = vi(n+1, 1);
		dfs2(1, 0);
		int c = cent(1, 0, n);

		dp = vll(n+1);
		lli v1 = dfs(c, 0, 1);

		multiset<lli> st1, st11, st2, st22;
		forr(i, 1, n+1) st1.insert(dp[i]);

		st11 = {(lli)1e12};

		for(auto e : graph[c]) {
			if(sze[e] == n/2) {
				c = e;
				dp = vll(n+1);
				lli v1 = dfs(c, 0, 1);
				st11 = {};
				forr(i, 1, n+1) st11.insert(dp[i]);
			}
		}

		graph = vvi(n+1);

		frange(i, n-1) {
			int a, b;
			scd(a);
			scd(b);
			graph[a].pb(b);
			graph[b].pb(a);
		}

		sze = vi(n+1, 1);
		dfs2(1, 0);
		c = cent(1, 0, n);

		dp = vll(n+1);
		lli v2 = dfs(c, 0, 1);

		forr(i, 1, n+1) st2.insert(dp[i]);

		st22 = {(lli)1e12+5};

		for(auto e : graph[c]) {
			if(sze[e] == n/2) {
				c = e;
				dp = vll(n+1);
				lli v1 = dfs(c, 0, 1);
				st22 = {};
				forr(i, 1, n+1) st22.insert(dp[i]);
			}
		}
		auto st1o = st1;
		auto st11o = st11;

		for(auto e : st2) {
			auto it = st1.find(e);
			auto it2 = st11.find(e);
			if(it != st1.end()) st1.erase(it);
			if(it2 != st11.end()) st11.erase(it2);
		}

		for(auto e : st22) {
			auto it = st1o.find(e);
			auto it2 = st11o.find(e);
			if(it != st1o.end()) st1o.erase(it);
			if(it2 != st11o.end()) st11o.erase(it2);
		}



		// printf("%lld %lld ", v1, v2);

		if(!st1.size() || !st1o.size() || !st11.size() || !st11o.size()) printf("YES\n");
		else printf("NO\n");
	}

}