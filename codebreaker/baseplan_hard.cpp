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
typedef long double ld;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int n;

vector<vii> minv, maxv;
vi vec;

void init() {
    maxv = minv = vector<vii>(20, vii(n));
    frange(i, n) {
    	maxv[0][i] = minv[0][i] = mp(vec[i], i);
    }

    forr(i, 1, 20) {
        frange(j, n) {
            minv[i][j] = min(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
            maxv[i][j] = max(maxv[i-1][j], maxv[i-1][min(n-1, j+(1<<(i-1)))]);
        }
    }
}

pii query_min(int l, int r) {
    int ln = r - l +1;
    int msb = 31 - __builtin_clz(ln);

    return min(minv[msb][l], minv[msb][r-(1<<msb)+1]);
    // return mp(0, 0);
}

pii query_max(int l, int r) {
    int ln = r - l +1;
    int msb = 31 - __builtin_clz(ln);

    return max(maxv[msb][l], maxv[msb][r-(1<<msb)+1]);
    // return mp(0, 0);
}

map<pii, lli> mv;

lli rec(int l, int r) {
	// printf("%d %d\n", l, r);
	if(l > r) return 0;
	
	if(l == r) {
		return 1;
	}
	if(mv.find(mp(l, r)) != mv.end()) return mv[mp(l, r)];
	pii mi = query_min(l, r);
	pii ma = query_max(l, r);
	int v1 = ma.f - mi.f + 1;
	int v2 = r - l + 1;
	lli cnt = 0;
	if(v1 <= v2) cnt++;
	// printf("%d %d %d %d %d %d\n", l, r, mi.s, ma.s, ma.f, ma.s);
	cnt += rec(l, max(mi.s, ma.s)-1);
	cnt += rec(min(mi.s, ma.s)+1, r);
	cnt -= rec(min(mi.s, ma.s)+1, max(mi.s, ma.s)-1);
	mv[mp(l, r)] = cnt;
	return cnt;
}

int main() {
	// usaco();
	scd(n);
	vec = vi(n);

	frange(i, n) {
		scd(vec[i]);
		vec[i]--;
	}
	init();
	printf("%lld", rec(0, n-1));
}