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
    int n;
    scd(n);
    lli m;
    sclld(m);

    vll v1(n/2), v2((n+1)/2);

    frange(i, n/2) sclld(v1[i]);
    frange(i, (n+1)/2) sclld(v2[i]);
    vll val1, val2;
    frange(i, 1<<(n/2)) {
        lli tot = 0;
        frange(j, n/2) {
            if(i&(1<<j)) {
                tot += v1[j];
            }
        }
        val1.pb(tot);
    }

    frange(i, 1<<((n+1)/2)) {
        lli tot = 0;
        frange(j, (n+1)/2) {
            if(i & (1<<j)) {
                tot += v2[j];
            }
        }
        val2.pb(tot);
    }

    sort(all(val1));
    sort(all(val2));

    lli c = 0;

    for(auto e : val1) {
        c += upper_bound(all(val2), m - e) - val2.begin();
    }
    printf("%lld", c);
}