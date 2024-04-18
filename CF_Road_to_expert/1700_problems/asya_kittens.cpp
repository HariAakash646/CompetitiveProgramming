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

vi graph;
vii disset;
vi sze;

int findf(int x)
{
    while (x != disset[x].f)
    {
        x = disset[x].f;
    }
    return x;
}

void unionf(int x, int y)
{
    int x1 = findf(x);
    int y1 = findf(y);
    if (sze[x1] < sze[y1])
    {
        swap(x1, y1);
        swap(x, y);
    }
    sze[x1] = max(sze[x1], sze[y1] + 1);
    disset[y1] = {x1, 0};
    disset[x1].s = y;
}

int main()
{
    int n;
    scd(n);
    graph = vi(n + 1);
    disset = vii(n + 1);
    sze = vi(n + 1);
    forr(i, 1, n + 1) disset[i] = {i, i};
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        if (sze[findf(a)] < sze[findf(b)])
            swap(a, b);
        int pre = disset[findf(a)].s;
        unionf(a, b);
        graph[pre] = b;
    }
    vb vis(n + 1);
    forr(i, 1, n + 1)
    {
        int x = findf(i);
        if (i == 2)
            printf("%d\n", x);
        if (!vis[x])
        {
            while (x)
            {
                vis[x] = true;
                printf("%d ", x);
                x = graph[x];
            }
        }
    }
}