#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
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

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    scd(n);
    vii vec(n);
    frange(i, n)
    {
        scd(vec[i].s);
        scd(vec[i].f);
    }
    sort(all(vec));
    int i1 = 0;
    int i2 = n - 1;
    int ma = 0;
    while (i1 <= i2)
    {
        int tot = vec[i1].f + vec[i2].f;
        int sub = min(vec[i1].s, vec[i2].s);
        vec[i1].s -= sub;
        vec[i2].s -= sub;
        if (vec[i1].s <= 0)
            i1++;
        if (vec[i2].s <= 0)
            i2--;
        ma = max(ma, tot);
    }
    printf("%d", ma);
}