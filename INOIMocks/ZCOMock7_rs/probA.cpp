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

int main() {
	// usaco();
	int n, m;
	scd(n);
	scd(m);

	vector<pair<int, pii>> vec(m);

	frange(i, m) {
		scd(vec[i].s.f);
		vec[i].s.f--;
		scd(vec[i].s.s);
		vec[i].s.s--;
		scd(vec[i].f);
	}

	sort(all(vec));
	vi out(n, 1);

	for(auto p : vec) {
		out[p.s.f] = p.f;
		out[p.s.s] = p.f;
	}

	for(auto e : out) printf("%d ", e);
}