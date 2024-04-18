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

long long bfs(int n, long long k, vector<int> P, vector<int> F) {
	vii vec(n);
	frange(i, n) {
		vec[i].f = P[i];
		vec[i].s = F[i];
	}
	sort(all(vec), greater<>());
	lli ma = 0;
	lli tot = 0;
	priority_queue<lli> pq;
	for(auto p : vec) {
		pq.push(p.s);
		tot += p.s;
		while(pq.size() && pq.top() >= p.f) {
			tot -= pq.top();
			pq.pop();
		}
		while(tot > k) {
			tot -= pq.top();
			pq.pop();
		}
		ma = max(ma, lli(p.f) * lli(pq.size()) - tot);
	}
	return ma;
}