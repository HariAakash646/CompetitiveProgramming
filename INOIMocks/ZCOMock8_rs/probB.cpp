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

vector<pair<int, lli>> vec;
vll out;

void build(int l, int r, vector<pair<pii, pii>> val) {
	if(l > r) return;
	if(l == r) {
		for(auto p : val) {
			if(p.f.f >= vec[l].f) out[p.f.s] = vec[l].s;
		}
		return;
	}
	int mid = (l+r)/2;
	int l1 = mid - l + 1;
	int l2 = r - mid;
	vector<vll> dp1(l1+1, vll(2001));
	vector<vll> dp2(l2+1, vll(2001));
	for(int i=mid; i>=l; i--) {
		forr(j, 1, 2001) {
			dp1[i-l][j] = max(dp1[i-l+1][j],dp1[i-l][j-1]);
			if(j - vec[i].f >= 0) {
				dp1[i-l][j] = max(dp1[i-l][j], dp1[i-l+1][j - vec[i].f] + vec[i].s);
			} 
		}
	}

	forr(i, mid+1, r+1) {
		forr(j, 1, 2001) {
			dp2[i-mid][j] = max(dp2[i-mid-1][j], dp2[i-mid][j-1]);
			if(j - vec[i].f >= 0) {
				dp2[i-mid][j] = max(dp2[i-mid][j], dp2[i-mid-1][j - vec[i].f] + vec[i].s);
			} 
		}
	}

	vector<pair<pii, pii>> lv, rv;
	for(auto p : val) {
		if(p.s.f <= mid && p.s.s > mid) {
			lli ma = 0;
			frange(i, p.f.f+1) {
				// printf("%d %d %d | %d %d %d\n", l, p.s.f, mid, mid+1, p.s.s, r);
				ma = max(ma, dp2[p.s.s-mid][i] + dp1[p.s.f-l][p.f.f-i]);
			} 
			out[p.f.s] = ma;
		}
		else {
			if(p.s.s <= mid) lv.pb(p);
			else rv.pb(p);
		}
	}
	build(l, mid, lv);
	build(mid+1, r, rv);


}

int main() {
	// usaco();
	int n;
	scd(n);

	vec = vector<pair<int, lli>>(n);

	frange(i, n) {
		scd(vec[i].f);
		sclld(vec[i].s);
	}

	int q;
	scd(q);
	vector<pair<pii, pii>> quer(q);

	out = vll(q);

	frange(i, q) {
		scd(quer[i].s.f);
		scd(quer[i].s.s);
		quer[i].s.f--;
		quer[i].s.s--;
		scd(quer[i].f.f);
		quer[i].f.s = i;
	}

	build(0, n-1, quer);

	frange(i, q) printf("%lld\n", out[i]);

}