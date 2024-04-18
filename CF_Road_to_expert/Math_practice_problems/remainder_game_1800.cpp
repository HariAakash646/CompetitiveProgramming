// TLE
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

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vi vec(n);
    int ma = k;
    frange(i, n)
    {
        scd(vec[i]);
        ma = max(ma, vec[i]);
    }
    int sq = sqrt(ma) + 1;
    vb prim(sq + 1, true);
    vll primvec;
    forr(i, 2, sq + 1)
    {
        if (prim[i])
        {
            primvec.pb(i);
            for (lli j = lli(i) * lli(i); j < sq + 1; j += i)
            {
                prim[j] = false;
            }
        }
    }
    vi facn(ma + 1);
    for (auto e : vec)
    {
        for (auto p : primvec)
        {
            if (p * p > e)
                break;
            int c = 0;
            while (e % p == 0)
            {
                c++;
                e /= p;
            }
            facn[p] = max(c, facn[p]);
            if (e <= 1)
                break;
        }

        if (e >= 2)
        {
            facn[e] = max(facn[e], 1);
            primvec.pb(e);
        }
    }
    vi fack(ma + 1);
    for (auto e : primvec)
    {
        if (e * e > k)
            break;
        while (k % e == 0)
        {
            fack[e]++;
            k /= e;
        }
    }
    if (k >= 2)
    {
        fack[k]++;
        primvec.pb(k);
    }
    bool no = false;
    for (auto i : primvec)
    {
        if (fack[i] > facn[i])
        {
            printf("NO");
            no = true;
            break;
        }
    }
    if (!no)
    {
        printf("YES");
    }
}