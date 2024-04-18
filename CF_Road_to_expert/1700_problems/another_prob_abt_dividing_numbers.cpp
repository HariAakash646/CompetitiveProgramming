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

vi prime;

int cnt_fac(int x)
{
    int c = 0;
    for (auto e : prime)
    {
        if (e * e > x)
            break;
        while (x % e == 0)
        {
            x /= e;
            c++;
        }
    }
    if (x > 1)
        c++;
    return c;
}

int main()
{
    int t;
    scd(t);
    int sz = 1e7;
    vb sieve(sz, true);
    sieve[0] = false;
    sieve[1] - false;

    forr(i, 2, sz)
    {
        if (sieve[i])
        {
            for (int j = 2 * i; j < sz; j += i)
            {
                sieve[j] = false;
            }
            prime.pb(i);
        }
    }
    frange(_, t)
    {
        int a, b, k;
        scd(a);
        scd(b);
        scd(k);
        int m;
        if (a > b)
            swap(a, b);
        if (b % a == 0 && a != b)
        {
            m = 1;
        }
        else
            m = 2;
        int c = cnt_fac(a) + cnt_fac(b);

        if (k == 1)
        {
            if (k <= c && m == 1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else if (m <= k && k <= c)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}