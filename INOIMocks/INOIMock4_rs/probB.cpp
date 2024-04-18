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

int main() {
	// usaco();
	int r, c;
	scd(r);
	scd(c);

	vvi grid(r, vi(c));

	frange(i, r) {
		frange(j, c) {
			scd(grid[i][j]);
		}
	}

	vector<vvi> rmi(r, vvi(c, vi(c, 1e9))), cmi(c, vvi(r, vi(r, 1e9))), rma(r, vvi(c, vi(c, 0))), cma(c, vvi(r, vi(r, 0)));

	frange(i, r) {
		frange(j, c) {
			forr(k, j, c) {
				rma[i][j][k] = rmi[i][j][k] = grid[i][k];
				if(k > 0) rmi[i][j][k] = min(rmi[i][j][k], rmi[i][j][k-1]);
				if(k > 0) rma[i][j][k] = max(rma[i][j][k], rma[i][j][k-1]);
			}
		}
	}

	frange(i, c) {
		frange(j, r) {
			forr(k, j, r) {
				cma[i][j][k] = cmi[i][j][k] = grid[k][i];
				if(k > 0) cmi[i][j][k] = min(cmi[i][j][k], cmi[i][j][k-1]);
				if(k > 0) cma[i][j][k] = max(cma[i][j][k], cma[i][j][k-1]);
			}
		}
	}
	int cnt = 0;
	frange(i, r) {
		frange(j, c) {

			forr(i1, i+2, r) {
				int ma = 0;
				forr(j1, j+2, c) {
					ma = max(ma, cma[j1-1][i+1][i1-1]);
					int mi = min({rmi[i][j+1][j1-1], rmi[i1][j+1][j1-1], cmi[j][i+1][i1-1], cmi[j1][i+1][i1-1]});
					if(mi > ma) cnt++;
				}
			}
		}
	}
	printf("%d", cnt);


}