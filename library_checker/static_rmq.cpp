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

int n;

vvi minv;
vi vec;

void init() {
    minv = vvi(20, vi(n));
    frange(i, n) minv[0][i] = vec[i];

    forr(i, 1, 20) {
        frange(j, n) {
            minv[i][j] = min(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
        }
    }
}

int query(int l, int r) {
    int ln = r - l +1;
    int msb = 31 - __builtin_clz(ln);

    return min(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}

int main() {
    // usaco();
    int q;
    scd(n);
    scd(q);

    vec = vi(n);
    frange(i, n) scd(vec[i]);

    init();
    frange(_, q) {
        int l, r;
        scd(l);
        scd(r);
        printf("%d\n", query(l, r-1));
    }
}