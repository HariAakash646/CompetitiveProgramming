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

vi vec;
vvi minv;

void init(int n) {
	minv = vvi(20, vi(n));
	frange(i, n) minv[0][i] = vec[i];

	forr(i, 1, 20) {
		frange(j, n) minv[i][j] = min(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
	}
}

int query(int l, int r) {
	int len = r - l + 1;
	int msb = 31 - __builtin_clz(len);

	return min(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vec = vi(n);
    frange(i, n) scd(vec[i]);

    init(n);
    frange(_, q) {
        int l, r;
        scd(l);
        scd(r);
        printf("%d\n", query(l, r-1));
    }
}