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
typedef long double ld;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct line {
	lli m, c;

	lli evaluate(lli x) {
		return m * x + c;
	}

	ld intersect(line &l2) {
		return ld(l2.c - c) / ld(m - l2.m);
	}
};

int main() {
	// usaco();
	int n;
	scd(n);

	vll vec(n+1);
	forr(i, 1, n+1) sclld(vec[i]);

	vector<pair<lli, int>> elem;
	elem.pb(mp(vec[1], 1));
	vb vis(n+1);
	forr(i, 2, n+1) {
		if(vec[i] > elem.back().f) {
			elem.pb(mp(vec[i], i));
		}
		else elem.back().s++;
	}
	vector<lli> dp(n+1, 1e18);
	dp[0] = 0;

	deque<line> dq;
	dq.pb({0, 0});

	for(auto p : elem) {
		lli v = p.f;
		int i = p.s;
		while(dq.size() >= 2 && dq.front().evaluate(v) >= dq[1].evaluate(v)) dq.pop_front();
		lli val = v * n + dq.front().evaluate(v);
		dp[i] = val;
		line lt = {-i, val};

		while(dq.size() >= 2 && lt.intersect(dq[dq.size()-2]) <= dq.back().intersect(dq[dq.size()-2])) dq.pop_back();
		dq.pb(lt);
	}
	printf("%lld", dp[elem.back().s]);
}