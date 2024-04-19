#include <bits/stdc++.h>

using namespace std;

#define forr(i, j, k) for(int i=j; i<k; i++)
#define frange(i, k) forr(i, 0, k)
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(vec) vec.begin(), vec.end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long lli;
typedef vector<lli> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> seti;
typedef map<int, int> mpii;
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int bsze=0;

struct Query {
	int l, r, id;

	bool operator<(Query y) {
		if(l /bsze == y.l / bsze) return r < y.r;
		else return l/bsze < y.l/bsze;
	}
};

int main() {
	// usaco();
	int n;
	scd(n);

	vi vec(n);

	frange(i, n) scd(vec[i]);
	bsze = sqrt(n);
	int q;
	scd(q);
	vector<Query> quer(q);

	frange(i, q) {
		scd(quer[i].l);
		scd(quer[i].r);
		quer[i].l--;
		quer[i].r--;
		quer[i].id = i;
	}

	sort(all(quer));

	int l = 0;
	int r = 0;
	vi cnt(1e6+1);
	cnt[vec[0]]++;
	int c = 1;

	vi out(q);

	for(auto p : quer) {
		while(r < p.r) {
			r++;
			if(!cnt[vec[r]]) c++;
			cnt[vec[r]]++;
		}
		while(l > p.l) {
			l--;
			if(!cnt[vec[l]]) c++;
			cnt[vec[l]]++;
		}
		while(r > p.r) {
			cnt[vec[r]]--;
			if(!cnt[vec[r]]) c--;
			r--;
		}
		while(l < p.l) {
			cnt[vec[l]]--;
			if(!cnt[vec[l]]) c--;
			l++;
		}
		out[p.id] = c;
	}
	for(auto e : out) printf("%d\n", e);
}