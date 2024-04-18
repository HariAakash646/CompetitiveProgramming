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
// #define f first
// #define s second
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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int n, m;
    lli p;
    scd(n);
    scd(m);
    sclld(p);
    vll v1(n), v2(m);

    frange(i, n) {
        sclld(v1[i]);
    }
    frange(i, m) sclld(v2[i]);

    sort(all(v1));
    sort(all(v2));

    vll pref(m);
    pref[0] = v2[0];
    forr(i, 1, m) pref[i] = pref[i-1] + v2[i];

    lli tot = 0;

    for(auto e : v1) {
        int id = upper_bound(all(v2), p - e) - v2.begin();

        if(id > 0) {
            tot += id * e + pref[id-1];
        }

        tot += p * (m-id);
    }
    printf("%lld", tot);
}