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
        int n, k;
        scd(n);
        scd(k);
        vvi grid(n, vi(n));
        frange(i, n)
        {
            frange(j, n)
            {
                scd(grid[i][j]);
            }
        }
        int c = 0;
        int c2 = 0;
        frange(i, n / 2)
        {
            frange(j, n)
            {
                if (grid[i][j] != grid[n - 1 - i][n - 1 - j])
                    c++;
            }
        }
        if (n % 2)
        {
            frange(j, n / 2)
            {
                if (grid[n / 2][j] != grid[n / 2][n - 1 - j])
                    c++;
            }
        }
        if (c <= k && ((c - k) % 2 == 0 || n % 2 == 1))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}