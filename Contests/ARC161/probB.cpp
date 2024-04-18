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
    int t;
    scd(t);
    frange(_, t)
    {
        lli x;
        sclld(x);
        if (x < 7)
        {
            printf("-1\n");
            continue;
        }
        else
        {
            lli c = __builtin_popcountll(x);
            // printf("%lld --\n", c);
            if (c >= 3)
            {
                if (c > 3)
                {
                    for (lli i = 0; i < 64; i++)
                    {
                        // if (i > 31)
                        // {
                        //     printf("%lld %d\n", i, x & 1LL << i);
                        // }
                        if (x & (1LL << i))
                        {
                            x = x ^ (1LL << i);
                            c--;
                            // printf("%d\n", i);
                        }
                        if (c == 3)
                            break;
                    }
                }
                printf("%lld\n", x);
            }
            else
            {
                bool next = false;
                if (c == 2)
                {
                    int id;
                    frange(i, 64)
                    {
                        if (x & (1LL << i))
                        {
                            x = x ^ (1LL << i);
                            id = i;
                            break;
                        }
                    }
                    if (id <= 1)
                    {
                        next = true;
                    }
                    else
                    {
                        for (int i = id - 1; i >= id - 2; i--)
                        {
                            x = x | (1LL << i);
                        }
                        printf("%lld\n", x);
                    }
                }
                if (c == 1 || next)
                {
                    int id;
                    frange(i, 64)
                    {
                        if (x & (1LL << i))
                        {
                            x = x ^ (1LL << i);
                            id = i;
                        }
                    }
                    for (int i = id - 1; i >= id - 3; i--)
                    {
                        x = x | (1LL << i);
                    }
                    printf("%lld\n", x);
                }
            }
        }
    }
}