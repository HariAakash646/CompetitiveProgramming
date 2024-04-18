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
	lli x;
	scd(n);
	sclld(x);

	vll del(n+1), wgt(n+1);
	forr(i, 1, n+1) sclld(del[i]);
	forr(i, 1, n+1) sclld(wgt[i]);

	vll prefd(n+1), prefw(n+1);
	forr(i, 1, n+1) {
		prefd[i] = prefd[i-1] + del[i];
		prefw[i] = prefw[i-1] + wgt[i];
	}

	deque<int> dq;
	dq.pb(0);

	lli ma = 0;

	forr(i, 1, n+1) {
		while(dq.size() && prefw[i] - prefw[dq.front()] > x) dq.pop_front();
		while(dq.size() && prefd[i] <= prefd[dq.back()]) dq.pop_back();
		dq.pb(i);
		ma = max(ma, prefd[i] - prefd[dq.front()]);
	}

	printf("%lld", ma);
}