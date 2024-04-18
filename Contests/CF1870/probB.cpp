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
    int t;
    scd(t);
    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        vll v1(n);
        vll v2(m);
        lli val = 0;
        frange(i, n) {
            sclld(v1[i]);
        }
        frange(i, m) {
            sclld(v2[i]);
            val = val | v2[i];
        }
        vll v3 = v1;
        if(n % 2 == 1) {
            lli mi = 0;
            lli ma = 0;
            for(auto e : v1) {
                mi = mi ^ e;
                ma = ma ^ (e | val);
            }
            printf("%lld %lld\n", mi, ma);
        }
        else {
            lli mi = 0;
            lli ma = 0;
            for(auto e : v1) {
                mi = mi ^ (e | val);
                ma = ma ^ e;
            }
            printf("%lld %lld\n", mi, ma);
        }

    }
}