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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	vll vec(n+1);
	forr(i, 1, n+1) sclld(vec[i]);

	sort(all(vec));

	vector<pair<lli, pii>> off(m+1);

	forr(i, 1, m+1) {
		sclld(off[i].f);
		scd(off[i].s.f);
		scd(off[i].s.s);
	}

	sort(all(off));

	vector<vll> dist(m+1, vll(n+1));

	forr(i, 1, m+1) {
		forr(j, 1, n+1) {
			dist[i][j] = dist[i][j-1] + abs(off[i].f - vec[j]);
		}
	}

	vector<vll> dp(m+1, vll(n+1, 1e18));
	dp[0][0] = 0;

	forr(i, 1, m+1) {
		deque<pair<lli, int>> dq;
		forr(j, 0, n+1) {
			while(dq.size() && dq.front().s < j-off[i].s.s) dq.pop_front();
			lli v = 1e17;
			if(j-off[i].s.f>=0) {
				v = dp[i-1][j-off[i].s.f] - dist[i][j-off[i].s.f];
				while(dq.size() && dq.back().f >= v) dq.pop_back();
				
				dq.pb(mp(v, j-off[i].s.f));
			}

			// for(auto p : dq) printf("%d|%lld ", p.s, p.f);
			// printf("\n");
			if(dq.size()) dp[i][j] = dq.front().f + dist[i][j];
			// printf("%lld ", dp[i][j]);
		}
		// printf("*****************\n");
	}
	if(dp[m][n] < 1e17)
	printf("%lld", dp[m][n]);
	else printf("-1");
}