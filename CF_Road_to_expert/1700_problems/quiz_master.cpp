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

void fact(int x, int m, vi &out)
{
    forr(i, 1, min(m + 1, int(sqrt(x) + 1)))
    {
        if (x % i == 0)
        {
            out.pb(i);
            if (x / i <= m)
                out.pb(x / i);
        }
    }
    if (x <= m)
        out.pb(x);
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n);
        vvi factors(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        sort(all(vec));
        frange(i, n)
        {
            fact(vec[i], m, factors[i]);
        }
        vi cnt(m + 1, 0);
        int c = 0;
        int mi = 1e9;
        int i1 = -1;
        int i2 = -1;
        // for (auto e : factors[i1])
        // {
        //     if (cnt[e] == 0)
        //         c++;
        //     cnt[e]++;
        // }
        // if (c == m)
        //     mi = 0;
        while (i1 < n)
        {
            i1++;
            if (i1 > 0)
            {
                for (auto e : factors[i1 - 1])
                {
                    cnt[e]--;
                    if (cnt[e] == 0)
                        c--;
                }
            }
            bool done = false;
            while (c < m)
            {
                i2++;
                if (i2 >= n)
                {
                    // printf("%d %d\n", c, i1, i2);
                    // for (auto e : cnt)
                    // {
                    //     printf("%d ", e);
                    // }
                    // printf("\n");
                    done = true;
                    break;
                }
                for (auto e : factors[i2])
                {
                    if (cnt[e] == 0)
                        c++;
                    cnt[e]++;
                }
            }
            if (!done)
            {
                mi = min(mi, vec[i2] - vec[i1]);
            }
            else
                break;
        }
        if (mi <= 1e5)
            printf("%d\n", mi);
        else
            printf("-1\n");
    }
}