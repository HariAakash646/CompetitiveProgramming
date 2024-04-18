#include <bits/stdc++.h>

using namespace std;

#define scd(x) scanf("%d", &x)
#define sclld(x) scanf("%lld", &x)
#define frange(i, n) for(int i=0; i<n; i++)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;


void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, k;
	scd(n);
	scd(k);

	vll vec(n+1);
	set<pii> seg;
	vll pref(n+1);
	set<pair<pair<lli, int>, pii>> val;
	lli tot = 0;
	int c = 0;
	forr(i, 1, n+1) {
		sclld(vec[i]);
		pref[i] = pref[i-1] + vec[i];
		if(vec[i] >= 0) {
			c++;
			tot += vec[i];
			val.insert(mp(mp(vec[i], 1), mp(i, i)));
			seg.insert(mp(i, i));
		}
	}

	vii tmp;
	auto it = seg.begin();

	while(it != prev(seg.end())) {
		auto p1 = *it;
		it++;
		auto p2 = *it;
		val.insert(mp(mp(abs(pref[p2.f-1] - pref[p1.s]), 0), mp(p1.s+1, p2.f-1)));		
		tmp.pb(mp(p1.s+1, p2.f-1));
		
	}

	for(auto p : tmp) seg.insert(p);

	while(c > k) {
		auto p = *val.begin();
		val.erase(val.begin());
		if(seg.find(p.s) == seg.end()) continue;
		// printf("%lld %d %d\n", p.f, p.s.f, p.s.s);
		tot -= p.f.f;
		c--;
		auto it = seg.find(p.s);
		if(it != seg.begin() && it != prev(seg.end())) {
			auto p1 = *prev(it);
			auto p2 = *next(it);
			seg.erase(next(it));
			it = seg.find(p.s);
			seg.erase(prev(it));
			it = seg.find(p.s);
			seg.erase(it);
			seg.insert(mp(p1.f, p2.s));
			if(p.f.s)
				val.insert(mp(mp(-(pref[p2.s] - pref[p1.f-1]), 0), mp(p1.f, p2.s)));
			else val.insert(mp(mp((pref[p2.s] - pref[p1.f-1]), 1), mp(p1.f, p2.s)));
		}
		else {
			pii er1 = {-1,-1}, er2={-1, -1};
			if(it != prev(seg.end())) er1 = *next(it);
			if(it != st.begin()) er2 = *prev(it);

			seg.erase(it);
			if(er1.f != -1) seg.erase(er1);
			if(er2.f != -1) seg.erase(er2);
		}
	}

	printf("%lld", tot);

	


}