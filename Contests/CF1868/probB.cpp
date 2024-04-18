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

lli dist(pair<lli, lli> p1, pair<lli, lli> p2) {
    return abs(p1.f - p2.f) + abs(p1.s - p2.s); 
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, k, a, b;
        scd(n);
        scd(k);
        scd(a);
        scd(b);
        a--;
        b--;
        vector<pair<lli, lli>> vec(n);
        frange(i, n) {
            sclld(vec[i].f);
            sclld(vec[i].s);
        }
        lli mi = dist(vec[a], vec[b]);
        lli mia = 1e18;
        lli mib = 1e18;
        frange(i, k) {
            mia = min(mia, dist(vec[a], vec[i]));
            mib = min(mib, dist(vec[b], vec[i]));
        }
        printf("%lld\n", min(mi, mia + mib));

    }
}