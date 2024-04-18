#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
	// usaco();
	int n;
	scd(n);
	lli l;
	sclld(l);

	vll vec(n+1);
	forr(i, 1, n+1) sclld(vec[i]);

	vll pref(n+1);
	forr(i, 1, n+1) pref[i] = pref[i-1] + vec[i];

	vvi lift(20, vi(n+2));
	lift[0][n+1] = n+1;
	forr(i, 1, n+1) {
		auto it = upper_bound(all(pref), pref[i-1] + l);
		lift[0][i] = it - pref.begin();
		// printf("%d ", lift[0][i]);
	}

	forr(i, 1, 20) {
		forr(j, 1, n+2) lift[i][j] = lift[i-1][lift[i-1][j]];
	}

	forr(i, 1, n+1) {
		int c = 0;
		int x = i;
		for(int j=19; j>=0; j--) {
			int xt = lift[j][x];
			if(xt != n+1) {
				x = xt;
				c += (1<<j);
				// printf("%d ", c);
			}
		}
		printf("%d %lld\n", c+1, pref[n] - pref[x-1]);
	}

}