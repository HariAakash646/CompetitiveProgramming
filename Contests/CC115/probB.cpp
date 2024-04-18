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
	int t;
	scd(t);

	frange(_, t) {
		int n;
		scd(n);
		vi vec(n);
		frange(i, n) scd(vec[i]);
		
		vi ord;

		ord.pb(vec[0]);

		forr(i, 1, n) {
			if(vec[i] <= ord.back()) ord.pb(vec[i]);
		}

		int mi = n;
		int x = ord.size();

		frange(i, ord.size()) {
			int v = ord[i] + n - (x - i);
			mi = min(mi, v);
		}
		printf("%d\n", mi);

	}
}