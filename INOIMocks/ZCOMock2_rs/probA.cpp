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

int main() {
	// usaco();
	int n;
	lli a, b;
	scd(n);
	sclld(a);
	sclld(b);

	vector<pair<lli, int>> vec(n);

	frange(i, n) {
		lli x, y;
		sclld(x);
		sclld(y);
		vec[i] = mp(abs(x-a) + abs(y-b), i+1);
	}

	sort(all(vec));
	for(auto p : vec) printf("%d ", p.s);
}