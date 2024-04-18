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

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int n, m;
vii vec;

// bool check1() {
// 	forr(i, 1, m) {
// 		if(abs(vec[i].s - vec[i-1].s) > vec[i].f - vec[i-1].f) return false;
// 	}
// 	return true;
// }

// bool check2() {
// 	vvi dp(m+1, vi(m+1));
// 	dp[0][0] = 1;
// 	forr(i, 0, m+1) {
// 		frange(j, m+1) {
// 			if(i > j) {

// 			}
// 		}
// 	}
// }

bool cmp1(pii x, pii y) {
	return x.s-x.f < y.s-y.f;
}

bool cmp2(pii x, pii y) {
	return x.s +x.f > y.s+y.f;
}

int main() {
	// usaco();
	scd(n);
	scd(m);

	vec = vii(m); 

	frange(i, m) {
		scd(vec[i].f);

	}
	frange(i, m) scd(vec[i].s);
	sort(all(vec));
	vector<vector<pair<vii, vii>>> dp(m, vector<pair<vii, vii>>(m));

	frange(i, m) {
		dp[i][i].f.pb(vec[i]);
		dp[i][i].s.pb(vec[i]);
		
	}

	forr(i, 1, m) {
		for(int l=0; l+i<m; l++) {
			int r = l+i;
			bool done1 = false;
			sort(all(dp[l+1][r].f), cmp1);
			auto v1 = dp[l+1][r].f;
			int id1 = 0;
			frange(i, v1.size()) {
				auto p = v1[i];
				if(abs(p.s - vec[l].s) <= abs(p.f - vec[l].f)) {
					done1 = true;
					id1 = i;
					break;
				}
			}
			
			if(!done1) {
				v1.pb(vec[l]);
			}
			
			bool done2 = false;
			sort(all(dp[l][r-1].s), cmp2);
			auto v2 = dp[l][r-1].s;
			// sort(all(v2), greater<>());
			int id2 = 0;
			frange(i, v2.size()) {
				auto p = v2[i];
				if(abs(p.s - vec[r].s) <= abs(p.f - vec[r].f)) {
					done2 = true;
					id2 = i;
					break;
				}
			}
			
			if(!done2) {
				v2.pb(vec[r]);
			}
			if(v1.size() < v2.size()) {
				// if(done2) {v2.pop_back();}
				// if(done1) {v2.pb(vec[l]);}

				dp[l][r] = dp[l+1][r];
				if(!done1) {
					dp[l][r].f.pb(vec[l]);
					dp[l][r].s.pb(vec[l]);
				}
				else dp[l][r].f[id1] = vec[l];

			}
			else {
				dp[l][r] = dp[l][r-1];
				if(!done2) {
					dp[l][r].f.pb(vec[r]);
					dp[l][r].s.pb(vec[r]);
				}
				else dp[l][r].s[id2] = vec[r];
			}
		}
	}
	printf("%d", (int)dp[0][m-1].f.size());
}