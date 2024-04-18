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
	int n, k;
	scd(n);
	scd(k);

	vll vec(n+1);
	lli tot1 = 0;
	lli tot2 = 0;
	int neg = -1;
	forr(i, 1, n+1) {
		sclld(vec[i]);
		tot1 += vec[i];
		if(vec[i] >= 0) tot2+=vec[i];
		else neg = i;
	}
	if(k > 1) {
		printf("%lld", tot2);
	}
	else {
		if(neg != -1) {
			lli v1 = 0;
			lli v2 = 0;
			forr(i, 1, neg) v1 += vec[i];
			forr(i, neg+1, n+1) v2 += vec[i];
			printf("%lld", max({v1, v2, tot1}));
		}
		else {
			printf("%lld", tot1);
		}
	}
}