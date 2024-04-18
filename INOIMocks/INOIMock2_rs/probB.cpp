#include <bits/stdc++.h>

using namespace std;

#define scd(x) scanf("%d", &x)
#define sclld(x) scanf("%lld", &x)
#define frange(i, n) for(int i=0; i<n; i++)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define all(vec) vec.begin(), vec.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<lli> vll;
typedef vector<bool> vb;


void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n, k;
	scd(n);
	scd(k);

	vll vec(n+1);
	forr(i, 1, n+1) sclld(vec[i]);

	vector<vll> dp1(n+1, vll(k+1, -1e17)), dp2(n+1, vll(k+1, -1e17));
	dp2[0][0] = 0;

	forr(i, 1, n+1) {
		forr(j, 0, k+1) {
			dp1[i][j] = dp1[i-1][j] + vec[i];
			if(j - 1 >=0) {
				dp1[i][j] = max(dp1[i][j], dp2[i-1][j-1] + vec[i]);
			}
			dp2[i][j] = max(dp2[i-1][j], dp1[i][j]);
		}
	}
	printf("%lld", *max_element(all(dp2[n])));
}