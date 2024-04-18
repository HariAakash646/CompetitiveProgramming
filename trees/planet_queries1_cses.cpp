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
    int n, q;
    scd(n);
    scd(q);
    vi tree(n + 1);
    forr(i, 1, n + 1)
    {
        scd(tree[i]);
    }
    int po = 0;
    while (1 << po <= 1e9)
        po++;
    vvi vec(po + 1, vi(n + 1, 0));
    forr(i, 1, n + 1)
    {
        vec[0][i] = tree[i];
    }
    forr(i, 1, po + 1)
    {
        forr(j, 1, n + 1)
        {
            vec[i][j] = vec[i - 1][vec[i - 1][j]];
        }
    }
    frange(_, q)
    {
        int x, k;
        scd(x);
        scd(k);
        int i = 0;
        while (k)
        {
            if (k % 2)
            {
                x = vec[i][x];
            }
            k /= 2;
            i++;
        }
        if (x)
            printf("%d\n", x);
        else
            printf("-1\n");
    }
}