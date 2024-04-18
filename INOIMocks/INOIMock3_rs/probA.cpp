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
	int n, m, k;
	scd(n);
	scd(m);
	scd(k);

	vector<vll> dist(n+1, vll(n+1, 1e18));

	forr(i, 1, n+1) dist[i][i] = 0;

	frange(i, m) {
		int a, b;
		scd(a);
		scd(b);
		lli v;
		sclld(v);
		dist[a][b] = min(dist[a][b], v);
		dist[b][a] = min(dist[b][a], v);
	}

	frange(_, 3) {forr(r, 1, n+1) {
			forr(i, 1, n+1) {
				forr(j, 1, n+1) {
					dist[i][j] = min(dist[i][j], dist[i][r] + dist[r][j]);
				}
			}
		}}

	// forr(i, 1, n+1) {
	// 	forr(j, 1, n+1) {
	// 		printf("%lld ", dist[i][j]);
	// 	}
	// 	printf("\n");
	// }

	vi vec(k);
	frange(i, k) scd(vec[i]);

	vector<vector<pair<lli, int>>> val(n+1);

	// forr(i, 1, n+1) {
	// 	forr(j, 1, n+1) {
	// 		val[i].pb(mp(dist[i][j], j));
	// 	}
	// 	sort(all(val[i]));
	// }
	frange(i, k) {
		frange(j, k) {
			if(i != j) val[vec[i]].pb(mp(dist[vec[i]][vec[j]], vec[j]));
		}
		sort(all(val[vec[i]]));
		// for(auto e : val[vec[i]]) printf("%lld ", e.f);
		// printf("\n");
	}
	lli ma = 1e18;
	frange(e, k) {
		frange(p, k) {
			int i = vec[e];
			int j = vec[p];
			if(i == j) continue;
			lli v = dist[i][j];
			frange(q, k) {
				int l = vec[q];
				if(l == i || l == j) continue;
				if(val[l][0].s != i && val[l][0].s != j) ma = min(ma, v + val[l][0].f);
				else if(val[l][1].s != i && val[l][1].s != j) ma = min(ma, v + val[l][1].f);
				else ma = min(ma, v + val[l][2].f);
			}
		}
	}
	printf("%lld", ma);

}