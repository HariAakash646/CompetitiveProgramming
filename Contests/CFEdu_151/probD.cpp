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

int n;
vll vec;

lli tot(lli k)
{
    lli tot = 0;
    for (auto e : vec)
    {
        if (tot >= k)
        {
            tot = max(k, tot + e);
        }
        else
            tot += e;
    }
    return tot;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        scd(n);
        vec = vll(n);
        frange(i, n) sclld(vec[i]);
        lli l = 0;
        lli r = 1e18;
        while (r - l > 3)
        {
            lli m1 = l + (r - l) / 3;
            lli m2 = r - (r - l) / 3;
            lli f1 = tot(m1);
            lli f2 = tot(m2);
            if (f1 < f2)
                l = m1 + 1;
            else
                r = m2 - 1;
        }
        lli ma = tot(l);
        lli mid = l;
        forr(i, l + 1, r)
        {
            if (tot(i) > ma)
            {
                ma = tot(i);
                mid = i;
            }
        }
        printf("%lld\n", mid);
    }
}