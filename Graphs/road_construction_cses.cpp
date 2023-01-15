#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vi dis;
vi sze;
int con;
int ma = 0;

int findf(int node)
{
    if (node != dis[node])
    {
        dis[node] = findf(dis[node]);
    }
    return dis[node];
}

void unionf(int a, int b)
{
    int posa = findf(a);
    int posb = findf(b);
    int sza = sze[posa];
    int szb = sze[posb];
    if (sza < szb)
        swap(posa, posb);
    dis[posb] = posa;
    sze[posa] += sze[posb];
    ma = max(ma, sze[posa]);

    --con;
}

bool same(int a, int b)
{
    return findf(a) == findf(b);
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    con = n;
    dis = vi(n + 1, 0);
    forr(i, 1, n + 1)
    {
        dis[i] = i;
    }
    sze = vi(n + 1, 1);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        if (!same(a, b))
        {
            unionf(a, b);
        }
        printf("%d %d\n", con, ma);
    }
}