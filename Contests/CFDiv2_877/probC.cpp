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
    vb sieve(1001, true);
    sieve[0] = false;
    sieve[1] = false;
    forr(i, 2, 1001)
    {
        if (sieve[i])
        {
            for (int j = 2 * i; j <= 1000; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        int ma = n * m;
        vvi vec(n, vi(m));
        if (!sieve[n])
        {
            int c = 1;
            frange(i, m)
            {
                frange(j, n)
                {
                    vec[j][i] = c;
                    c++;
                }
            }
        }
        else if (!sieve[m])
        {
            int c = 1;
            frange(i, n)
            {
                frange(j, m)
                {
                    vec[i][j] = c;
                    c++;
                }
            }
        }
        else
        {
            vi val(n);
            int c = 0;
            frange(i, n)
            {
                val[i] = c;
                c += 2;
                if (c >= n)
                {
                    c = 1;
                }
            }
            frange(i, n)
            {
                frange(j, m)
                {
                    vec[i][j] = val[i] * m + j + 1;
                }
            }
        }
        frange(i, n)
        {
            frange(j, m)
            {
                printf("%d ", vec[i][j]);
            }
            printf("\n");
        }
    }
}