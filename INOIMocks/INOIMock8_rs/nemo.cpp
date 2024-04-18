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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

vi disset, sze;

int findf(int x) {
	while(x != disset[x]) {
		x = disset[x];
	}
	return x;
}

void unionf(int x, int y) {
	x = findf(x);
	y = findf(y);
	if(x == y) return;
	if(sze[y] > sze[x]) swap(x, y);
	disset[y] = x;
	sze[x] = max(sze[x], sze[y]+1); 
}

int main() {
	// usaco();
	int n, e;
	scd(n);
	scd(e);

	vector<pair<int, pii>> opn(e), cls(e);

	frange(i, e) {
		int a, b;
		int o, c;
		scd(a);
		scd(b);
		a++;
		b++;
		scd(o);
		scd(c);
		opn[i] = mp(o, mp(a, b));
		cls[i] = mp(c, mp(a, b));
	}

	sort(all(opn));
	sort(all(cls), greater<>());

	int ti = opn[e-1].f;

	int q;
	scd(q);

	vector<pair<int, pii>> quer(q);

	vector<pair<pii, pii>> quer1, quer2;
	frange(i, q) {
		int a, b, t;
		scd(a);
		scd(b);
		a++;
		b++;
		scd(t);
		quer[i] = mp(t, mp(a, b));
		if(t <= ti) quer1.pb(mp(mp(t, i), mp(a, b)));
		else quer2.pb(mp(mp(t, i), mp(a, b)));
	}

	sort(all(quer1));
	vi out(q, -1);

	sze = disset = vi(n+1);

	forr(i, 1, n+1) disset[i] = i;

	int id = -1;
	for(auto p : quer1) {
		// printf("%d %d\n", p.f.f, opn[id+1].f);
		while((id < (int)opn.size() - 1) && opn[id+1].f <= p.f.f) {
			id++;
			unionf(opn[id].s.f, opn[id].s.s);
			// printf("%d %d\n", opn[id].s.f, opn[id].s.s);
		}
		out[p.f.s] = findf(p.s.f) == findf(p.s.s);
	}

	sort(all(quer2), greater<>());

	sze = disset = vi(n+1);

	forr(i, 1, n+1) disset[i] = i;

	id = -1;
	for(auto p : quer2) {
		while(id < (int)cls.size() -1 && cls[id+1].f >= p.f.f) {
			id++;
			unionf(cls[id].s.f, cls[id].s.s);
		}
		out[p.f.s] = findf(p.s.f) == findf(p.s.s);
	}

	frange(i, q) {
		// printf("%d ", out[i]);
		if(out[i]) printf("Y\n");
		else printf("N\n");
	}
}