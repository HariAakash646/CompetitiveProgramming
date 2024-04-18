#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    int n;
    scd(n);
    vvi grid(101, vi(101));

    frange(i, n)
    {
        int a, b, c, d;
        scd(a);
        scd(b);
        scd(c);
        scd(d);
        forr(i, a, b)
        {
            forr(j, c, d)
            {
                grid[i][j]++;
            }
        }
    }

    int c = 0;
    frange(i, 101)
    {
        frange(j, 101)
        {
            if (grid[i][j])
                c++;
        }
    }
    printf("%d", c);
}