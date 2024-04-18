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

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

pair<ld, ld> a, b, p1, p2;

bool check(ld x) {
    if(dist(a, p1) <= x && dist(a, p2) <= x) return true;
    if(dist(b, p1) <= x && dist(b, p2) <= x) return true;

    if(dist(a, p1) <= x && dist(b, p2) <= x && dist(a, b) <= 2 * x) return true;
    return false;
}

int main() {
    // usaco();
    int t;
    scd(t);
    p1 = mp(0, 0);
    frange(_, t) {
        int x, y;
        scd(x);
        scd(y);
        p2 = mp(x, y);

        scd(x);
        scd(y);
        a = mp(x, y);

        scd(x);
        scd(y);
        b = mp(x, y);

        if(dist(b, p1) < dist(a, p1)) swap(a, b);

        ld lo = 0;
        ld hi = 4e6;

        while(hi - lo > 1e-7) {
            ld mid = (lo + hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid;
        }
        printf("%Lf\n", lo);
    }
}