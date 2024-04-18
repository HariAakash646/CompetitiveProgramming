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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, a, b;
	scd(n);
	scd(a);
	scd(b);

	vll vec(n);
	lli tot = 0;

	frange(i, n) {
		lli u;
		sclld(u);
		vec[i] = u;
	}

	frange(i, n) {
		lli v;
		sclld(v);
		tot += v;
		vec[i] -= v;
	}

	sort(all(vec), greater<>());

	frange(i, a) {
		tot += vec[i];
	}

	printf("%lld", tot);
}