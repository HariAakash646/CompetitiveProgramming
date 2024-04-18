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
	int t;
	scd(t);

	frange(_, t) {
		int n, x;
		scd(n);
		scd(x);
		if(n == 1) {
			if(x == 1) printf("-1\n");
			else printf("1\n");
			continue;
		}
		else {
			if(n - x <= 1) printf("-1\n");
			else {
				printf("%d ", n);
				for(int i=x+1; i>=1; i--) printf("%d ", n-i);
				forr(i, x+2, n) printf("%d ", n-i);
				printf("\n");
			}
		}
	}
}