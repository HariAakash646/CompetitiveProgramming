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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vector<lli> vecg;
vector<lli> veca;
int g, a;

lli check(lli v)
{
    lli tot = 0;
    frange(i, g)
    {
        auto itr = upper_bound(all(veca), v - vecg[i]);
        if (itr == veca.begin())
            break;
        tot += itr - veca.begin();
    }
    return tot;
}

int main()
{

    lli n;
    scd(g);
    scd(a);
    sclld(n);
    vecg = vector<lli>(g);
    veca = vector<lli>(a);
    bool g1 = true;
    frange(i, g)
    {
        sclld(vecg[i]);
        if (vecg[i] != 1)
            g1 = false;
    }
    frange(i, a)
    {
        sclld(veca[i]);
    }
    sort(all(veca));
    sort(all(vecg));
    if (g1)
    {
        lli tot = 0;
        int idx = 0;
        while (n - g >= 0)
        {
            tot += g * veca[idx];
            tot += g;
            idx++;
            n -= g;
        }
        tot += n * veca[idx];
        tot += n;
        printf("%lld", tot);
        return 0;
    }
    lli l = 1;
    lli h = veca[a - 1] + vecg[g - 1];
    while (l != h)
    {
        lli mid = (l + h) / 2;
        if (check(mid) >= n)
        {
            h = mid;
        }
        else
            l = mid + 1;
    }
    --l;
    vector<lli> prefa(a + 1);
    vector<lli> prefg(g + 1);
    forr(i, 1, a + 1)
    {
        prefa[i] = veca[i - 1] + prefa[i - 1];
    }
    forr(i, 1, g)
    {
        prefg[i] = vecg[i - 1] + prefg[i - 1];
    }
    int num = 0;
    lli tot = 0;
    int idx = 0;
    int lastg, lasta;
    while (true)
    {

        auto itr = upper_bound(all(veca), l - vecg[idx]);
        if (itr == veca.begin())
            break;
        int pd = itr - veca.begin();
        tot += prefa[pd];
        tot += vecg[idx] * pd;
        lasta = pd;
        lastg = idx;
        num += pd;
        idx++;
        if (idx >= g)
            break;
        if (num >= n)
            break;
    }
    tot += (n - num) * (l + 1);
    printf("%lld", tot);
}