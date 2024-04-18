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
typedef vector<vll> vvll;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef pair<int, pii> piii;

vi disset;
vi sze;
vi sze2;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    sze2[x] += sze2[y];
}

int main()
{
    const int max_n = 1e5;
    int n, m;
    scd(n);
    scd(m);
    disset = vi(n + 1);
    sze = vi(n + 1, 1);
    sze2 = vi(n + 1, 1);
    forr(i, 1, n + 1) disset[i] = i;
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        unionf(a, b);
    }
    vi comp;
    vb vis(n + 1, false);
    forr(i, 1, n + 1)
    {
        int x = findf(i);
        if (!vis[x])
        {
            vis[x] = true;
            comp.pb(sze2[x]);
        }
    }
    bitset<max_n + 1> bs;
    bs[0] = true;
    for (auto e : comp)
    {
        bs |= (bs << e);
    }
    forr(i, 1, n + 1)
    {
        if (bs[i])
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}