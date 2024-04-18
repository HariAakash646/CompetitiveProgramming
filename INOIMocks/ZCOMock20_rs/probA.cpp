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
}

vi disset, sze;

int findf(int x) {
	if(x == disset[x]) return x;
	disset[x] = findf(disset[x]);
	return disset[x];
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
	int n, r, c;
	scd(n);scd(r);
	scd(c);

	map<int, set<pair<pii, int>>> add, rem;
	vector<pair<pii, pii>> vec(n);

	frange(i, n) {
		int w, x, y, z;
		scd(w);
		scd(x);
		scd(y);
		scd(z);
		vec[i] = mp(mp(w, x), mp(y, z));
		add[x].insert(mp(mp(w, y), i));
		rem[z].insert(mp(mp(w, y), i));
	} 

	set<pair<pii, int>> st, st2;
	auto it = rem.begin();

	sze = disset = vi(n);

	frange(i, n) disset[i] = i;

	for(auto v : add) {
		while(it != rem.end()) {
			if((*it).f < v.f) {
				for(auto x : (*it).s) {
					st.erase(x);
					st2.erase(mp(mp(x.f.s, x.f.f), x.s));
				}
				it++;
			}
			else break;
		}
		set<pair<pii, int>> stt;
		if(rem.find(v.f-1) != rem.end())
			stt = rem[v.f-1];
		for(auto p : v.s) {
			auto it = st.upper_bound(mp(mp(p.f.s, 1e9), 1e9));
			if(it != st.end()) {
				auto p1 = *it;

				if(p1.f.f == p.f.s+1) {
					unionf(p1.s, p.s);
				}
			}
			auto it2 = st2.lower_bound(mp(mp(p.f.f, 0), 0));
			if(it2 != st2.begin()) {
				it2--;
				auto p1 = *it2;
				// printf("%d %d %d %d\n", p.f.f, p1.f.f, p.s, p1.s);
				if(p1.f.f == p.f.f-1) {
					unionf(p1.s, p.s);
				}
			}
			st.insert(p);
			st2.insert(mp(mp(p.f.s, p.f.f), p.s));
			if(stt.size()) {
				
				auto it = stt.lower_bound(mp(mp(p.f.f, 0), 0));
				auto it2 = it;
				while(it != stt.end()) {
					auto p1 = *it;
					if(p1.f.f <= p.f.s) {
						unionf(p1.s, p.s);
						it++;
					}
					else break;
				}
				it = it2;
				if(it != stt.begin()) {
					it--;
					auto p1 = *it;
					if(p1.f.s >= p.f.f) {
						unionf(p1.s, p.s);
					}
				}
			}
		}
	}

	vii pos(n, mp(1e9, 1));

	frange(i, n) {
		int p = findf(i);
		// printf("%d %d\n", i, p);
		pos[p].f = min(pos[p].f, vec[i].f.f);
		pos[p].s = max(pos[p].s, vec[i].s.f);
	}

	frange(i, n) {
		// printf("%d %d\n", pos[i].f, pos[i].s);
		if(pos[i] == mp(1, r)) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");

}