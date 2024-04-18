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

int n, m;
vvi vec;

bool check(int x)
{
    vb vis(n);
    bool done = false;
    frange(i, m)
    {
        int c = 0;
        frange(j, n)
        {
            if (vec[i][j] >= x)
            {
                vis[j] = true;
                c++;
            }
        }
        if (c >= 2)
            done = true;
    }
    for (auto b : vis)
    {
        if (!b)
            done = false;
    }
    return done;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        scd(m);
        scd(n);
        vec = vvi(m, vi(n));
        frange(i, m)
        {
            frange(j, n)
            {
                scd(vec[i][j]);
            }
        }
        int lo = 1;
        int hi = 1e9;
        while (lo != hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (check(mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        printf("%d\n", lo);
    }
}