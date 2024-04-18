#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}
 
int main() {
	// usaco();
	int n;
	scd(n);
 
	vector<pair<int, pii>> vec(n);
	int tot = 0;
	frange(i, n) {
		scd(vec[i].s.f);
		tot += vec[i].s.f;
		scd(vec[i].f);
		scd(vec[i].s.s);
	}
 
	sort(all(vec), greater<>());
 
	int m;
	scd(m);
 
	vector<pair<int, pii>> cust(m);
 
	frange(i, m) {
		scd(cust[i].s.f);
		scd(cust[i].f);
		scd(cust[i].s.s);
	}
 
	sort(all(cust), greater<>());
	int id = 0;
 
	lli pre[50*2000+1];
	lli dp[50*2000+1];

	forr(i, 1, tot+1) {
		pre[i] = -1e18;
		dp[i] = -1e18;
	}

	pre[0] = dp[0] = 0;
 
	frange(i, m) {
		
 
		while(id < n && vec[id].f >= cust[i].f) {
			forr(j, vec[id].s.f, tot+1) {
				dp[j] = max(dp[j], pre[j-vec[id].s.f] - vec[id].s.s);
			}
			forr(j, 0, tot+1)
				pre[j] = dp[j];
			id++;
		}
 
		forr(j, 0, tot+1) {
			if(j + cust[i].s.f <= tot) {
				dp[j] = max(dp[j], pre[j+cust[i].s.f] + cust[i].s.s);
				// printf("%d %d %lld\n", i, j, dp[j]);
			}
			else break;
		}
		forr(j, 0, tot+1)
			pre[j] = dp[j];
	}
	lli ma = 0;
 	frange(i, tot+1) ma = max(ma, pre[i]);
	printf("%lld", ma);
 
}