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
typedef long double ld;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct line {
	lli m, c;

	lli eval(lli x) {
		return m * x + c;
	}

	ld intersect(line y) {
		return ld(y.c - c) / ld(m - y.m);
	}
};

int main() {
	// usaco();
	int n;
	scd(n);
	vector<pair<lli, lli>> vec(n+1);

	forr(i, 1, n+1) {
		sclld(vec[i].f);
		sclld(vec[i].s);
	}

	sort(all(vec), greater<>());

	lli ma = 0;

	vector<pair<lli, lli>> val;
	for(auto p : vec) {
		if(p.s > ma) {
			ma = p.s;
			val.pb(p);
		}
	}

	vll dp(n+1, 1e18);
	dp[0] = 0;

	deque<line> dq;
	line tmp;
	if(val.size() >= 2) {tmp.m = val[0].f;
		tmp.c = 0;
		dq.pb(tmp);
		lli v = 0;
		frange(i, val.size()) {
			auto p = val[i];
			while(dq.size() >= 2 && dq[1].eval(p.s) <= dq[0].eval(p.s)) dq.pop_front();
			v = dq[0].eval(p.s);
			if(i < (int)val.size()-1) {
				line l = {val[i+1].f, v};
				while(dq.size() >= 2 && dq[dq.size()-2].intersect(l) <= dq[dq.size()-2].intersect(dq.back())) {
					dq.pop_back();
				}
				dq.pb(l);
			}
		}
		printf("%lld", v);
	}
	else {
		printf("%lld", val[0].f * val[0].s);
	}
}