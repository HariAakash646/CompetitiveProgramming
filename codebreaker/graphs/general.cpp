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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vi disset, sze, po, head;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

bool unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return false;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    if (po[y] > po[x])
    {
        po[x] = po[y];
        head[x] = head[y];
    }
    return true;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    po = vi(n + 1);
    disset = vi(n + 1);
    sze = vi(n + 1, 1);
    head = vi(n + 1);
    forr(i, 1, n + 1) scd(po[i]);
    forr(i, 1, n + 1)
    {
        disset[i] = i;
        head[i] = i;
    }
    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        if (!unionf(a, b))
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", head[findf(a)]);
        }
    }
}