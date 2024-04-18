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

int n;
vii vec;

bool check(lli x) {
	vll val(n);
	frange(i, n) {
		lli v = x-vec[i].f;
		v /= vec[i].s;
		val[i] = v;
	}
	vi cnt(n+1);
	frange(i, n) {
		if(val[i] <= lli(n)) {
			cnt[val[i]]++;
			// printf("%lld\n", val[i]);
		}
	}
	forr(i, 1, n+1) {
		cnt[i] += cnt[i-1];
	}
	frange(i, n+1) {
		if(cnt[i] > i+1) return false;
	}
	return true;
}

int main() {
	// usaco();
	scd(n);
	vec = vii(n);
	lli lo = 0;
	lli hi = 1e15;
	frange(i, n) {
		scd(vec[i].f);
		scd(vec[i].s);
		lo = max(lo, (lli)vec[i].f);
	}

	while(lo != hi) {
		lli mid = (lo+hi)/2;
		if(check(mid)) hi = mid;
		else lo = mid+1;
	}

	printf("%lld", lo);

	
}