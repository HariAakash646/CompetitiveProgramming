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

vvi lift;
vector<vll> liftv;

lli binlift(int x, int k) {
	lli tot = 0;
	frange(i, 20) {
		if(k & (1<<i)) {
			tot += liftv[i][x];
			x = lift[i][x];
		}
	}
	return tot;
}

int main() {
	// usaco();
	int n, sh;
	lli k;
	scd(n);
	scd(sh);
	sclld(k);


	vll dist(n);
	dist[0] = 0;

	forr(i, 1, n) {
		lli v;
		sclld(v);
		dist[i] = dist[i-1] + v;
	}

	vll pref(n);

	vll val(n);

	frange(i, n) {
		sclld(val[i]);
		pref[i] = val[i];
		if(i > 0) pref[i] += pref[i-1];
	}

	// deque<pii> dq;
	// lli curr = 0;

	// lli ma = 0;

	// frange(i, n) {
	// 	int l = i;
	// 	while(dq.size() && (dist[i] - dist[dq.back().s]) <= k) {
	// 		l = dq.back().s;
	// 		dq.pop_back();
	// 	}
	// 	if(dq.size() && (dist[i] - dist[dq.back().f]) <= k);
	// 	else dq.pb(mp(i, l));

	// 	while(dq.size() > sh) {
	// 		int id = dq.front().f;
	// 		dq.pop_front();
	// 		curr -= val[id];
	// 	}
	// 	curr += val[i];
	// 	ma = max(ma, curr);
	// }

	// // printf("%lld\n", ma);
	// dq = {};
	// curr = 0;
	// frange(i, n) {
	// 	if(dq.size() && (dist[i] - dist[dq.back()]) <= 2*k);
	// 	else dq.pb(i);

	// 	while(dq.size() > sh) {
	// 		int id = dq.front();
	// 		dq.pop_front();
	// 		curr -= val[id];
	// 	}
	// 	curr += val[i];
		
	// 	if(curr == ma) {
	// 		printf("%d\n", (int)dq.size());
	// 		for(auto e : dq) printf("%d ", e+1);
	// 		return 0;
	// 	}
	// }

	lift = vvi(20, vi(n+1));
	liftv = vector<vll>(20, vll(n+1));

	frange(i, n) {
		int i1 = upper_bound(all(dist), dist[i] + k) - dist.begin() - 1;
		int i2 = upper_bound(all(dist), dist[i1] + k) - dist.begin() - 1;
		lift[0][i] = i2+1;
		liftv[0][i] = pref[i2];
		if(i > 0) liftv[0][i] -= pref[i-1];
	}

	lift[0][n] = n;

	forr(i, 1, 20) {
		frange(j, n+1) {
			lift[i][j] = lift[i-1][lift[i-1][j]];
			liftv[i][j] = liftv[i-1][j] + liftv[i-1][lift[i-1][j]];
		} 
	}

	pair<lli, int> ma = {0, 0};
	frange(i, n) {
		lli v = binlift(i, sh);
		ma = max(ma, mp(v, i));
	}

	vi out;
	int curr = ma.s;
	frange(i, sh) {	
		int i1 = upper_bound(all(dist), dist[curr] + k) - dist.begin() - 1;
		out.pb(i1+1);
		curr = lift[0][curr];
		if(curr == n) break;
	}	
	printf("%d\n", (int)out.size());
	for(auto e : out) printf("%d ", e);

}