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

vector<vector<pair<pii, pii>>> graph;
vi st, en, mv;
vi val, col, depth;
vvi lift, colp;
int timer = 1;

void dfs(int x, int p) {
	st[x] = timer++;
	lift[0][x] = p;
	for(auto e : graph[x]) {
		if(e.f.f != p) {
			val[e.f.f] = e.s.s;
			col[e.f.f] = e.s.f;
			colp[e.s.f].pb(e.f.f);
			depth[e.f.f] = depth[x]+1;
			mv[e.f.s] = e.f.f;
			dfs(e.f.f, x);
		}
	}
	en[x] = timer++;
}

int binlift(int x, int c) {
	frange(i, 20) {
		if(c & (1<<i)) x = lift[i][x];
	}
	return x;
}

int lca(int u, int v) {
	if(depth[v] > depth[u]) swap(u, v);
	u = binlift(u, depth[u]-depth[v]);
	if(v == u) return u;
	for(int i=19; i>=0; i--) {
		int ut = lift[i][u];
		int vt = lift[i][v];
		if(ut != vt) {
			u = ut;
			v = vt;
		}
	}
	return lift[0][u];
}

int main() {
	// usaco();
	int n, q;
	scd(n);
	scd(q);

	graph = vector<vector<pair<pii, pii>>>(n+1);
	vi cnt(n);

	frange(i, n-1) {
		int a, b, c, d;
		scd(a);
		scd(b);
		scd(c);
		scd(d);
		graph[a].pb(mp(mp(b, i+1), mp(c, d)));
		graph[b].pb(mp(mp(a, i+1), mp(c, d)));
		cnt[c]++;
	}

	mv = depth = st = en = val = col = vi(n+1);
	lift = vvi(20, vi(n+1));
	colp = vvi(n+1);
	dfs(1, 0);

	forr(i, 1, 20) {
		forr(j, 1, n+1) {
			lift[i][j] = lift[i-1][lift[i-1][j]];
		}
	}

	int buc = 0;
	int sq = sqrt(n);
	vi pos(n);
	vvi pref, ndc;
	vi val2(timer), tmp(timer);
	vi valsq;
	vector<pair<pii, int>> ran;
	int sq2 = sqrt(timer);

	forr(i, 1, n) {
		if(cnt[i] >= sq) {
			pos[i] = buc;
			valsq.pb(0);
			buc++;
			pref.pb(vi(timer));
			ndc.pb(vi(timer));
			int x = pref.size()-1;
			forr(j, 1, n+1) {
				if(col[j] == i) {
					pref[x][st[j]] += val[j];
					pref[x][en[j]] -= val[j];
					ndc[x][st[j]]++;
					ndc[x][en[j]]--;
				}
			}
			forr(j, 1, timer) {
				pref[x][j] += pref[x][j-1];
				ndc[x][j] += ndc[x][j-1];
			}
		}
		else {
			for(auto j : colp[i]) {
				val2[st[j]] += val[j];
				val2[en[j]] -= val[j];
			}
			
		}
	}
	vi ptr(timer);
	for(int i=0; i<timer; i+=sq2) {
		pair<pii, int> p = mp(mp(0, 0), 0);
		p.f.f = i;
		p.f.s = min(timer-1, i+sq2-1);
		for(int j=i; j<=p.f.s; j++) {
			p.s += val2[j];
			ptr[j] = ran.size();
		}
		ran.pb(p);
	}



	frange(_, q) {
		int x, y;
		scd(x);
		scd(y);
		int ty = 0;
		if(cnt[x] >= sq) {
			ty = valsq[pos[x]];
			valsq[pos[x]] = y;
		}
		else {
			for(auto e : colp[x]) {
				ran[ptr[st[e]]].s += y - val2[st[e]];
				ran[ptr[en[e]]].s -= val2[en[e]] + y;
				tmp[st[e]] = val2[st[e]];
				tmp[en[e]] = val2[en[e]];
				val2[st[e]] = y;
				val2[en[e]] = -y;
			}
		}
		int u, v;
		scd(u);
		scd(v);
		int l = lca(u, v);
		int lx = st[l]+1;
		int rx = st[u];
		lli tot = 0;
		frange(i, buc) {
			if(valsq[i]) {
				int c = ndc[i][rx] - ndc[i][lx-1];
				tot += c * valsq[i];
			}
			else {
				tot += pref[i][rx] - pref[i][lx-1];
			}
		}
		for(auto p : ran) {
			if(rx < p.f.f || lx > p.f.s) continue;
			else if(lx <= p.f.f && p.f.s <= rx) {
				tot += p.s;
			}
			else {
				for(int i=max(lx, p.f.f); i<=min(rx, p.f.s); i++) tot += val2[i];
			}
		}

		if(lx > rx) tot = 0;

		lx = st[l]+1;
		rx = st[v];
		frange(i, buc) {
			if(valsq[i]) {
				int c = ndc[i][rx] - ndc[i][lx-1];
				tot += c * valsq[i];
			}
			else {
				tot += pref[i][rx] - pref[i][lx-1];
			}
		}
		// printf("%d %d %d ", lx, rx, l);
		for(auto p : ran) {
			if(rx < p.f.f || lx > p.f.s) continue;
			else if(lx <= p.f.f && p.f.s <= rx) {
				tot += p.s;

			}
			else {
				for(int i=max(lx, p.f.f); i<=min(rx, p.f.s); i++) {
					tot += val2[i];
					// printf("%d ", p.s);
				}
			}
		}
		printf("%lld\n", tot);

		if(cnt[x] >= sq) {
			valsq[pos[x]] = ty;
		}
		else {
			for(auto e : colp[x]) {
				ran[ptr[st[e]]].s += tmp[st[e]] - val2[st[e]];
				ran[ptr[en[e]]].s -= val2[en[e]];
				ran[ptr[en[e]]].s += tmp[en[e]];
				
				val2[st[e]] = tmp[st[e]];
				val2[en[e]] = tmp[en[e]];
			}
		}
	}

}