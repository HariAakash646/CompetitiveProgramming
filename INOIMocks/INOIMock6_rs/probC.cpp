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
	int n, k;
	scd(n);
	scd(k);

	vi vec(n);

	frange(i, n) scd(vec[i]);

	vi pwd(n);
	frange(i, n) scd(pwd[i]);
	map<int, vi> val;
	frange(i, n) {
		if(vec[i] <= pwd[i]) {
			vec[i] = pwd[i] - vec[i];
		}
		else {
			vec[i] = k - vec[i] + 1 + pwd[i];
		}
		val[vec[i]].pb(i);
	}

	set<pii> ran;
	lli cnt = 0;

	ran.insert(mp(0, n-1));
	int curr = 0;

	for(auto p : val) {
		cnt += (p.f - curr) * lli(ran.size());
		for(auto e : p.s) {
			auto it = ran.upper_bound(mp(e, 1e9));
			it--;
			auto p1 = *it;
			ran.erase(it);
			if(p1.f <= e-1) ran.insert(mp(p1.f, e-1));
			if(p1.s >= e+1) ran.insert(mp(e+1, p1.s));
		}
		curr = p.f;
	}

	printf("%lld", cnt);


}