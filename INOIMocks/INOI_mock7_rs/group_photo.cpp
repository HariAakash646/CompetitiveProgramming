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

int main() {
	// usaco();
	int n;
	scd(n);

	vi vec(n);
	vi pos(n);
	frange(i, n) {
		scd(vec[i]);
		vec[i]--;
		pos[vec[i]] = i;
	}

	vector<vi> dp(1<<n, vi(n, 1e9));

	// forr(i, 1, 1<<n) {

	// 	frange(j, n) {
	// 		if(i & (1<<j)) {
	// 			if(__builtin_popcount(i) == 1) dp[i][j] = pos[j];
	// 			int k = i ^ (1<<j);
	// 			frange(l, n) {
	// 				if(k & (1<<l)) {
	// 					if(vec[j] + 2 > vec[l]) {
	// 						dp[i][j] = min(dp[i][j], dp[k][l] + abs(pos[j] - __builtin_popcount(k)));
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	sort(all(vec));
	int mi = 1e9;
	do {
		bool done = true;
		forr(i, 1, n) {
			if(vec[i] + 2 <= vec[i-1]) done = false;
		}
		if(!done) continue;
		int tot = 0;
		frange(i, n) tot += max(0, i - pos[vec[i]]);
		mi = min(mi, tot);
	}
	while(next_permutation(all(vec)));
	printf("%d\n", mi/2);
}