#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
	// usaco();
	int n, m, p;
	scd(n);
	scd(m);
	scd(p);
	vii vec(n);
	frange(i, n) {
		scd(vec[i].f);
		scd(vec[i].s);
	}
	sort(all(vec), greater<>());
	vb vis(n);
	lli tot = 0;
	frange(i, m) {
		tot += vec[i].f;
		vis[i] = true;
	}
	priority_queue<pii> ms, ns, ns2;

	frange(i, n) {
		if(vis[i]) {
			ms.push(mp(vec[i].s - vec[i].f, i));
			
		}
		else {
			ns.push(mp(vec[i].s, i));
			ns2.push(mp(vec[i].f, i));
		}
	}

	frange(i, p) {
		while(ns.size() && vis[ns.top().s]) ns.pop();
		while(ns2.size() && vis[ns2.top().s]) ns2.pop();
		int e1 = -1e9;

		if(ns.size()) e1 = ns.top().f;
		int e2 = -1e9;

		if(ns2.size() && ms.size()) {
			e2 = ms.top().f + ns2.top().f;
		}

		if(e1 > e2) {
			tot += e1;
			vis[ns.top().s] = true;
			ns.pop();

		}
		else {
			tot += e2;
			auto p = ms.top();
			auto p2 = ns2.top();
			ms.pop();
			ns2.pop();
			vis[p2.s] = true;
			ms.push(mp(vec[p2.s].s - vec[p2.s].f, i));
		}
	}
	printf("%lld", tot);
}