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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int gcd(int x, int y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

int main() {
	// usaco();
	int n, k;
	scd(n);
	scd(k);
	vll vec(n+1);
	forr(i, 1, n+1) sclld(vec[i]);

	vector<map<int, pair<lli, int>>> dp(n+1);
	dp[0][0] = mp(0, 0);
	lli ma = 0;
	forr(i, 0, n) {
		dp[i+1][0] = mp(0, 0);
		for(auto p : dp[i]) {
			int g = gcd(p.f, vec[i+1]);
			if(p.s.s >= k) {
				ma = max(ma, p.f * p.s.f);
			}
			if(p.s.s +1> dp[i+1][g].s)
				dp[i+1][g] = mp(p.s.f+ vec[i+1], p.s.s+1);
		}
		dp[i] = {};
	}
	
	for(auto p : dp[n]) {
		if(p.s.s >= k) {
			ma = max(ma, p.s.f * p.f);
		}
	}
	
	printf("%lld", ma);
}