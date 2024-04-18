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


int main()
{
    int n;
    scd(n);
    vi veca(n + 1);
    vi vecb(n + 1);
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        veca[a] = i;
    }
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        vecb[a] = i;
    }
    int l1 = n;
    int r1 = 1;
    int l2 = n;
    int r2 = 1;
    lli tot = 0;
    forr(i, 1, n+1) {
        int i1 = veca[i];
        int i2 = vecb[i];
        pii rl1, rr1, rl2, rr2;
        if(r1 < i1) {
            rl1 = {l1, i1-1};
        }
        if(l1 > i1) {
            rr1 = {i1+1, r1};
        }
        if(r2 < i2) {
            rl2 = {l2, i2-1};
        }
        if(l2 > i2) {
            rr2 = {i2+1, r2};
        }
        pii inter1;
    }
}