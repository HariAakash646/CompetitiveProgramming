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

lli mod = 1e9 + 7;

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}


int main() {
	// usaco();
	int t;
	cin >> t;

	frange(_, t) {
		int n, m;
		cin >> n >> m;
		vector<string> vec(n);
		frange(i, n) cin >> vec[i];

		if(n == 1) {
			printf("1\n");
			continue;
		}

		for(int i=n-2; i>=1; i--) {
			int c = 0;
			int on = 0;
			frange(j, m) {

				if(vec[i+1][j] == '1' && vec[i][j] == '1') {
					c++;
				}
				if(vec[i][j] == '1') on++;
			}
			if(on <= 1) {
				frange(j, m) vec[i][j] = '0';
				continue;
			}
			if(c) {
				frange(j, m) {
					if(vec[i+1][j] == '1') vec[i][j] = '1'; 
				}
			}
		}
		int c = 0;
		frange(i, m) {
			if(vec[1][i] == '1') c++;
		}

		int c2 = 0;
		frange(i, m) {
			if(vec[1][i] == '1' && vec[0][i] == '1') c2++;
		}

		lli v1 = 1;
		forr(i, 1, c+1) {
			v1 *= i;
			v1 %= mod;
		}

		lli v2 = 1;
		forr(i, 1, c2+1) {
			v2 *= i;
			v2 %= mod;
		}

		lli v3 = 1;
		forr(i, 1, (c-c2+1)) {
			v3 *= i;
			v3 %= mod;
		}

		lli out = v1 * inv(v2) % mod * inv(v3) % mod;
		printf("%lld\n", out);
	}
}