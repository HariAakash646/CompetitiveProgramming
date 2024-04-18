#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int n;
lli l;
vector<pair<lli, lli>> vec;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool check(ld x) {
    ld prev = 0;
    
    forr(i, 1, n+1) {
        auto p = vec[i];

        if(prev <= p.f && dist(p.f, p.s, prev, 0) > x) {
            continue;
        }
        ld v = sqrt(x*x - p.s * p.s) + p.f;
        
        prev = max(prev, v);
    }
    return prev >= l;
    
}

int main() {
    // usaco();

    
    scd(n);
    sclld(l);

    vec = vector<pair<lli, lli>>(n+1);

    forr(i, 1, n+1) {
        sclld(vec[i].f);
        sclld(vec[i].s);
    }

    ld lo = 0;
    ld hi = 4e9;

    while(hi - lo >= 1e-4) {
        ld mid = (lo + hi)/2;
        if(check(mid)) {
            hi = mid;
        }
        else lo = mid;
    }

    cout << fixed << setprecision(4) << lo << "\n";

}