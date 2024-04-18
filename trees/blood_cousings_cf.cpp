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

vvi binlift;
vvi cnt;
vector<vvi> bindown;
vi pow2(20);

int down(int x, int v)
{
    if (v == 0)
        return 1;
    frange(i, 20)
    {
        if (pow2[i] == v)
            return cnt[x][i];
    }
    frange(i, 20)
    {
        if (v & (1 << i))
        {
            int tot = 0;
            for (auto e : bindown[x][i])
            {
                tot += down(e, v ^ (1 << i));
            }
            return tot;
        }
    }
    return 1;
}

int lift(int x, int v)
{
    int tot = 0;
    int c = 0;
    frange(i, 20)
    {
        if (v & (1 << i))
        {
            x = binlift[x][i];
        }
    }
    return x;
}

int main()
{
    frange(i, 20) pow2[i] = 1 << i;
    int n, m;
    scd(n);
    cnt = binlift = vvi(n + 1, vi(20, 0));
    bindown = vector<vvi>(n + 1, vvi(20));
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        binlift[i][0] = a;
    }
    scd(m);
    forr(i, 1, 20)
    {
        forr(j, 1, n + 1)
        {
            binlift[j][i] = binlift[binlift[j][i - 1]][i - 1];
        }
    }

    forr(i, 1, n + 1)
    {
        frange(j, 20)
        {
            if (binlift[i][j])
            {
                cnt[binlift[i][j]][j]++;
                bindown[binlift[i][j]][j].pb(i);
            }
        }
    }

    frange(i, m)
    {
        int u, p;
        scd(u);
        scd(p);
        int v = down(lift(u, p), p);
        printf("%d ", max(0, v - 1));
    }
}