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

	vii vec(n+1);

	vvi graph(n+1);

	vi deg(n+1);

	forr(i, 1, n+1) {
		int l, r;
		scd(l);
		scd(r);
		if(l != -1) {
			deg[i]++;
			graph[l].pb(i);
		}
		if(r != -1) {
			deg[i]++;
			graph[r].pb(i);
		}
	}

	priority_queue<int> q;
	int v = n;

	vi out(n+1);

	forr(i, 1, n+1) {
		if(!deg[i]) q.push(i);
	}

	while(q.size()) {
		auto e = q.top();
		q.pop();

		out[e] = v--;
		for(auto x : graph[e]) {
			deg[x]--;
			if(deg[x] == 0) q.push(x);
		}
	}

	forr(i, 1, n+1) printf("%d ", out[i]);


}