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
	// usaco();
	int n;
	scd(n);

	vii vec(n);
	frange(i, n) {
		scd(vec[i].f);
		scd(vec[i].s);
	}

	vb vis(n, true);

	frange(i, n) {
		frange(j, n) {
			if(i != j && vec[i].s >= vec[j].s) {
				auto p = vec[i];
				
				if(vec[j].f <= vec[i].f) {
					p.f -= p.s - vec[j].s;
					if(p.f <= vec[j].f) vis[j] = false;
				}
				else {
					p.f += p.s - vec[j].s;
					if(p.f > vec[j].f) vis[j] = false;
				}
			}
		}
	}	
	int c = 0;
	frange(i, n) {
		if(vis[i]) c++;
	}
	printf("%d", c);
}