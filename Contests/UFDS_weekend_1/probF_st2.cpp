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
vi par, depth;
vvi graph;
int root;

int main()
{

    scd(n);
    scd(m);
    graph = vvi(n + 1);
    par = depth = vi(n + 1);
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        if (a == 0)
        {
            root = i;
        }
        else
        {
            par[i] = a;
            graph[i].pb(a);
            graph[a].pb(i);
        }
    }
    int en = n + 1;
    frange(i, m)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int x;
            scd(x);
            en -= x;
            printf("%d\n", en);
        }
        else
        {
            int y;
            scd(y);
            int v = y - en;
            en++;
            printf("%d\n", v);
        }
    }
}