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

int main() {
    // usaco();
    int a, b, c, d;
    scd(a);
    scd(b);
    scd(c);
    scd(d);
    vi v1(a), v2(b), v3(c), v4(d);
    frange(i, a) scd(v1[i]);

    frange(i, b) scd(v2[i]);

    frange(i, c) scd(v3[i]);

    frange(i, d) scd(v4[i]);

    vector<pair<int, pii>> val1;
    vector<pair<int, pii>> val2;

    frange(i, a) {
        frange(j, b) {
            val1.pb(mp(v1[i] + v2[j], mp(v1[i], v2[j])));
            // printf("%d %d %d\n", v1[i] + v2[j], v1[i], v2[j]);
        }
    }

    frange(i, c) {
        frange(j, d) {
            val2.pb(mp(v3[i] + v4[j], mp(v3[i], v4[j])));
            // printf("%d %d %d\n", v3[i] + v4[j], v3[i], v4[j]);
        }
    }
    sort(all(val1));
    sort(all(val2));
    for(auto p : val1) {
        auto it = lower_bound(all(val2), mp(-p.f, mp((int)-1e9, (int)-1e9)));
        if(it == val2.end()) continue;
        // printf("%d %d %d %d\n", p.s.f, p.s.s, (*it).s.f, (*it).s.s);
        if((*it).f == -p.f) {
            printf("%d %d %d %d\n", p.s.f, p.s.s, (*it).s.f, (*it).s.s);
            return 0;
        }
    }
    printf("-1");
}