// 80% corect
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

vvi vec;

int x, y, k, m;
void dfs(int i, int j, int it)
{
    if (it > k)
        return;
    if (vec[i][j] <= it)
        return;
    vec[i][j] = it;

    dfs(x, j, it + 1);
    dfs(i, y, it + 1);
    if (y - (x - i) >= 0)
    {
        dfs(x, y - (x - i), it + 1);
    }
    else if (i + j <= x)
    {
        dfs(i + j, 0, it + 1);
    }
    if (x - (y - j) >= 0)
    {
        dfs(x - (y - j), y, it + 1);
    }
    else if (i + j <= y)
    {
        dfs(0, i + j, it + 1);
    }
    dfs(0, j, it + 1);
    dfs(i, 0, it + 1);
}

int main()
{
    // freopen("pails.in", "r", stdin);
    // freopen("pails.out", "w", stdout);
    scd(x);
    scd(y);
    scd(k);
    scd(m);
    vec = vvi(x + 1, vi(y + 1, 1e9));
    int v = 0;
    dfs(0, 0, 0);
    frange(i, x + 1)
    {
        frange(j, y + 1)
        {
            if (vec[i][j] != 1e9)
            {
                int e = i + j;
                if (abs(m - e) < abs(m - v))
                {
                    v = e;
                }
            }
        }
    }
    printf("%d", abs(m - v));
}