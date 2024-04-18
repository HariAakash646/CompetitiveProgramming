#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
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
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
	// usaco();
	int n;
	scd(n);

	vi cnt(n+2);
	seti abs;

	forr(i, 1, n+2) abs.insert(i);

	frange(i, n) {
		int t, x;
		scd(t);
		scd(x);
		if(t == 1) {
			if(x <= n+1) {
				cnt[x]++;
				if(abs.find(x) != abs.end()) abs.erase(x);
			}
		}
		else {
			if(x <= n+1) {
				if(cnt[x]) {
					cnt[x]--;
					if(cnt[x] == 0) abs.insert(x);
				}
			}
		}
		printf("%d\n", *abs.begin()-1);
	}
}