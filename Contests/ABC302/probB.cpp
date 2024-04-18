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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);

    frange(i, h)
    {
        cin >> grid[i];
    }
    vector<char> vec = {'s', 'n', 'u', 'k', 'e'};
    frange(i, h)
    {
        frange(j, w)
        {
            bool l = true;
            bool r = true;
            bool u = true;
            bool d = true;
            bool ul = true;
            bool ur = true;
            bool dl = true;
            bool dr = true;

            frange(k, 5)
            {
                if (i + k >= h || grid[i + k][j] != vec[k])
                    d = false;
                if (i - k < 0 || grid[i - k][j] != vec[k])
                    u = false;
                if (j + k >= w || grid[i][j + k] != vec[k])
                    r = false;
                if (j - k < 0 || grid[i][j - k] != vec[k])
                    l = false;
                if (i + k >= h || j + k >= w || grid[i + k][j + k] != vec[k])
                    dr = false;
                if (i + k >= h || j - k < 0 || grid[i + k][j - k] != vec[k])
                    dl = false;
                if (i - k < 0 || j + k >= w || grid[i - k][j + k] != vec[k])
                    ur = false;
                if (i - k < 0 || j - k < 0 || grid[i - k][j - k] != vec[k])
                    ul = false;
            }
            if (d)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i + k, j);
                }
                break;
            }
            if (u)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i - k, j);
                }
                break;
            }
            if (r)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i, j + k);
                }
                break;
            }
            if (l)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i, j - k);
                }
                break;
            }
            if (dr)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i + k, j + k);
                }
                break;
            }
            if (dl)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i + k, j - k);
                }
                break;
            }
            if (ur)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i - k, j + k);
                }
                break;
            }
            if (ul)
            {
                i++;
                j++;
                frange(k, 5)
                {
                    printf("%d %d\n", i - k, j - k);
                }
                break;
            }
        }
    }
}