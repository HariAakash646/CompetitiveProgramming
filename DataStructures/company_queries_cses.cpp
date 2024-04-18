// Not working. Binary jumping issue.
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

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vi vec(n + 1, 0);
    forr(i, 2, n + 1)
    {
        scd(vec[i]);
    }
    int v = 1;
    int po = 0;
    while (v <= n / 2)
    {
        v *= 2;
        po++;
    }
    vvi tab(po + 1, vi(n + 1, 0));
    frange(i, po + 1)
    {
        forr(j, 1, n + 1)
        {
            if (i == 0)
            {
                tab[i][j] = vec[j];
            }
            else
            {
                tab[i][j] = tab[i - 1][tab[i - 1][j]];
            }
        }
    }
    int x, k;
    frange(i, q)
    {
        scd(x);
        scd(k);
        v = 1;
        po = 0;
        while (v <= k / 2)
        {
            v *= 2;
            po++;
        }
        while (k > 0)
        {
            if (k % 2 == 1)
            {
                x = tab[po][x];
            }
            k /= 2;
            po--;
        }
        if (x == 0)
            printf("-1 ");
        else
            printf("%d ", x);
    }
}