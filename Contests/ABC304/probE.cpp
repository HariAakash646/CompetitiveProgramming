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

vi disset, sze;

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
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    disset = sze = vi(n + 1);
    forr(i, 1, n + 1) disset[i] = i;

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);

        unionf(a, b);
    }

    int k;
    scd(k);
    set<pii> sep;
    frange(i, k)
    {
        int a, b;
        scd(a);
        scd(b);
        sep.insert({findf(a), findf(b)});
    }

    int q;
    scd(q);

    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        a = findf(a);
        b = findf(b);
        if (sep.find({a, b}) != sep.end() || sep.find({b, a}) != sep.end())
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}