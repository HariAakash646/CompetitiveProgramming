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

	vii vec(n, mp(-1, -1));
	vi deg(n);
	frange(i, n) {
		int l, r;
		scd(l);
		scd(r);
		if(l != -1) {
			vec[i].f = l-1;
			deg[l-1]++;
		}
		if(r != -1) {
			vec[i].s = r-1;
			deg[r-1]++;
		}
	}

	priority_queue<int> pq;
	frange(i, n) {
		if(deg[i] == 0) pq.push(-i);
	}

	vi out(n);
	int curr = 1;

	while(pq.size()) {
		int p = -pq.top();
		pq.pop();
		out[p] = curr++;
		if(vec[p].f != -1) {
			deg[vec[p].f]--;
			if(deg[vec[p].f] == 0) pq.push(-vec[p].f);
		}
		if(vec[p].s != -1) {
			deg[vec[p].s]--;
			if(deg[vec[p].s] == 0) pq.push(-vec[p].s);
		}
	}
	for(auto e : out) printf("%d ", e);
}