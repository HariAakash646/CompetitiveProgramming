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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);

    vi v1(n), v2(m);
    frange(i, n) scd(v1[i]);
    frange(i, m) scd(v2[i]);
    vi v3 = v1;
    vi v4 = v2;
    sort(all(v3));
    sort(all(v4));
    
    int id = n-1;
    vi sw1;
    int v = v3[id];
    int it = find(all(v1), v) - v1.begin();
    if(it != 0) {
        sw1.pb(it);
        vi tmp;
        forr(i, it, n) {
            tmp.pb(v1[i]);
        }
        tmp.pb(v1[it-1]);
        frange(i, it-1) tmp.pb(v1[i]);
        v1 = tmp;
    }
    id--;
    int cn = 0;
    for(auto e : v1) printf("%d ", e);
            printf("\n");
    while(id >= 0 && v1 != v3) {
        cn++;
        int v = v3[id];
        int it = find(all(v1), v) - v1.begin();
        sw1.pb(it+1);
        vi tmp;
        forr(i, it+1, n) {
            tmp.pb(v1[i]);
        }
        // it = find(all(v1), v) - v1.begin();
        tmp.pb(v1[it]);
        frange(i, it) tmp.pb(v1[i]);
        v1 = tmp;
        it = find(all(v1), v) - v1.begin();
        if(it != 0) {
            sw1.pb(it);
            tmp = {};
            forr(i, it, m) {
                tmp.pb(v1[i]);
            }
            tmp.pb(v1[it-1]);
            frange(i, it-1) tmp.pb(v1[i]);
            v1 = tmp;
        }
        for(auto e : v1) printf("%d ", e);
            printf("\n");
        id--;
        // tmp = {};
        // sw1.pb(it);
        // forr(i, it, n) {
        //     tmp.pb(v1[i]);
        // }
        // tmp.pb(v1[it-1]);
        // frange(i, it-1) tmp.pb(v1[i]);
        // v1 = tmp;
        // for(auto e : v1) printf("%d ", e);
        //     printf("\n");
    }

    id = m-1;
    vi sw2;
    v = v4[id];
    it = find(all(v2), v) - v2.begin();
    if(it != 0) {
        sw2.pb(it);
        vi tmp;
        forr(i, it, m) {
            tmp.pb(v2[i]);
        }
        tmp.pb(v2[it-1]);
        frange(i, it-1) tmp.pb(v2[i]);
        v2 = tmp;
    }
    for(auto e : v2) printf("%d ", e);
            printf("\n");
    id--;
    cn = 0;
    while(id >= 0 && v2 != v4) {
        cn++;
        int v = v4[id];
        int it = find(all(v2), v) - v2.begin();
        sw2.pb(it+1);
        vi tmp;
        forr(i, it+1, m) {
            tmp.pb(v2[i]);
        }
        // it = find(all(v2), v) - v2.begin();
        tmp.pb(v2[it]);
        frange(i, it) tmp.pb(v2[i]);
        v2 = tmp;
        it = find(all(v2), v) - v2.begin();
        if(it != 0) {
            sw2.pb(it);
            tmp = {};
            forr(i, it, m) {
                tmp.pb(v2[i]);
            }
            tmp.pb(v2[it-1]);
            frange(i, it-1) tmp.pb(v2[i]);
            v2 = tmp;
        }
        for(auto e : v2) printf("%d ", e);
            printf("\n");

        id--;
    }

    int c1 = sw1.size();
    int c2 = sw2.size();

    printf("%d %d\n", c1, c2);

    if(abs(c1 - c2) == 1) {
        printf("-1");
    }
    else {
        printf("%d\n", max(c1, c2));
        if(c2 > c1) {
            int d = c2 - c1;
            if(d % 2 != 0) {
                sw1.pb(n);
                sw1.pb(n);
            }
        }
        else {
            frange(i, c1-c2) v2.pb(1);
        }
        frange(i, max(c1, c2)) printf("%d %d\n", sw1[i], sw2[i]);
    }
}
