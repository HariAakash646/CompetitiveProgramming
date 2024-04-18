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
        int n, m;
        scd(n);
        scd(m);
        printf("? 1 1\n");
        fflush(stdout);
        int d;
        scd(d);
        int x = d + 1;
        printf("? %d %d\n", min(x, n), min(x, m));
        fflush(stdout);
        scd(d);
        if (n >= x && m >= x)
        {
            printf("? %d %d\n", x - d, min(x, m));
            fflush(stdout);
            scd(d);
            if (d)
            {
                printf("! %d %d\n", x, x - d);
            }
            else
            {
                printf("! %d %d\n", x - d, x);
            }
        }
        else if (n >= x)
        {
            printf("! %d %d\n", x, min(m, x) - d);
        }
        else if (m >= x)
        {
            printf("! %d %d\n", min(n, x) - d, x);
        }
        fflush(stdout);
    }
}