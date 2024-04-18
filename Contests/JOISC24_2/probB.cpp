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
    int n;
    scd(n);
    vi vec(2*n);
    frange(i, 2*n) scd(vec[i]);
    vi v1(n), v2(n);
    frange(i, n) scd(v1[i]);
    frange(i, n) scd(v2[i]);

    sort(all(v1));
    sort(all(v2));

    int mi = 2e9+10;

    frange(i, n+1) {
        vi vt1;
        forr(j, 0, i) vt1.pb(vec[j]);
        vi vt2;
        forr(j, i, i+n) vt2.pb(vec[j]);
        forr(j, i+n, 2*n) vt1.pb(vec[j]);
        sort(all(vt1));
        sort(all(vt2));
        int ma = 0;
        frange(i, n) {
            // printf("%d %d\n", v1[i], vt1[i]);
            // printf("%d %d\n", v2[i], vt2[i]);
            ma = max(ma, abs(v1[i] - vt1[i]));
            ma = max(ma, abs(v2[i] - vt2[i]));
        }
        // printf("%d\n", ma);
        mi = min(mi, ma);
        ma = 0;
        frange(i, n) {
            // printf("%d %d\n", v2[i], vt1[i]);
            // printf("%d %d\n", v1[i], vt2[i]);
            ma = max(ma, abs(v2[i] - vt1[i]));
            ma = max(ma, abs(v1[i] - vt2[i]));
        }
        // printf("%d\n", ma);
        mi = min(mi, ma);
    }
    printf("%d", mi);
}