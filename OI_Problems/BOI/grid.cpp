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

int n, m, r, p;
vvi grid;

bool check(int x, vi &vec) {
	vi tot(vec.size());
	int c = 0;
	frange(i, m) {
		int pre = 0;
		frange(k, vec.size()) {
			forr(j, pre, vec[k]+1) {
				tot[k] += grid[j][i];
			}
			pre = vec[k]+1;
			if(tot[k] > x) {
				c++;
				tot = vi(vec.size(), 0);
				int pre = 0;
				frange(k, vec.size()) {
					forr(j, pre, vec[k]+1) {
						tot[k] += grid[j][i];
					}
					pre = vec[k]+1;
					if(tot[k] > x) {
						return false;
					}
				}
				break;
			}
		}
	}
	return c <= p;
}

int val(int x) {
	vi vec;
	frange(i, n) {
		if(x & (1<<i)) {
			vec.pb(i);
		}
	}
	vec.pb(n-1);
	int lo = 0;
	int hi = 4e7;

	while(lo != hi) {
		int mid = (lo + hi)/2;
		if(check(mid, vec)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main() {
	// usaco();
	scd(n);
	scd(m);
	scd(r);
	scd(p);

	grid = vvi(n, vi(m));

	frange(i, n) {
		frange(j, m) {
			scd(grid[i][j]);
		}
	}
	int mi = 4e7;
	frange(i, 1<<(n-1)) {
		if(__builtin_popcount(i) == r) {
			mi = min(mi, val(i));
		}
	}
	printf("%d", mi);

}