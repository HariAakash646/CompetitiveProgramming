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

vector<vector<pair<int, lli>>> graph;
vvi lift;
vector<vll> liftv;
vi depth;

void dfs(int x, int p, int d) {
	lift[0][x] = p;
	depth[x] = d;
	for(auto e : graph[x]) {
		if(e.f != p) {
			dfs(e.f, x, d+1);
			liftv[0][e.f] = e.s; 
		}
	}
}

int binlift(int x, int c) {
	frange(i, 20) {
		if(c & (1<<i)) {
			x = lift[i][x];
		}
	}
	return x;
}

lli liftvl(int x, int c) {
	lli tot = 0;
	frange(i, 20) {
		if(c & (1<<i)) {
			tot += liftv[i][x];
			x = lift[i][x];
		}
	}
	return tot;
}

int lca(int a, int b) {
	if(depth[a] > depth[b]) swap(a, b);
	b = binlift(b, depth[b]-depth[a]);
	if(a == b) return a;

	for(int i=19; i>=0; i--) {
		int at = lift[i][a];
		int bt = lift[i][b];
		if(at != bt) {
			a = at;
			b = bt;
		}
	}
	return lift[0][a];
}

bool cmp(int x, int y) {
	return depth[x] > depth[y];
}

int main() {
	// usaco();
	int n;
	scd(n);

	graph = vector<vector<pair<int, lli>>>(n+1);

	frange(i, n-1) {
		int a, b;
		lli v;
		scd(a);
		scd(b);
		a++;
		b++;
		sclld(v);
		graph[a].pb(mp(b, v));
		graph[b].pb(mp(a, v));
	}

	depth = vi(n+1);
	lift = vvi(20, vi(n+1));
	liftv = vector<vll>(20, vll(n+1));

	dfs(1, 0, 0);

	forr(i, 1, 20) {
		forr(j, 1, n+1) {
			lift[i][j] = lift[i-1][lift[i-1][j]];
			liftv[i][j] = liftv[i-1][j] + liftv[i-1][lift[i-1][j]];
		}
	}
	int q;
	scd(q);
	vi vec(5);
	frange(_, q) {
		
		frange(i, 5) scd(vec[i]);
		frange(i, 5) vec[i]++;

		int l = vec[0];
		lli tot = 0;
		forr(i, 1, 5) {
			l = lca(l, vec[i]);
		}
		// printf("%d ", l);
		forr(i, 1, 32) {
			lli val = 0;
			int tl = -1;
			frange(j, 5) {
				
				if(i & (1<<j)) {
					if(tl == -1) tl = vec[j];
					else tl = lca(tl, vec[j]);
				}
			}
			val = liftvl(tl, depth[tl] - depth[l]);
			// printf("%d %lld\n", i, val);
			if(__builtin_popcount(i) % 2) tot += val;
			else tot -= val;
		}
		printf("%lld\n", tot);
	}

}