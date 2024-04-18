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

int n;
vll fenwick;

int lsb(int pos)
{
    return pos & -pos;
}

void update(int l, int r, lli v)
{
    fenwick[r] += v;
    if (r - lsb(r) + 1 == l)
    {
        return;
    }
    else if (r - lsb(r) + 1 < l)
    {
        update(r - lsb(r) + 1, l - 1, -v);
    }
    else if (r - lsb(r) + 1 > l)
    {
        update(l, r - lsb(r), v);
    }
}

lli query(int p)
{
    lli sum = 0;
    while (p <= n)
    {
        sum += fenwick[p];
        p += lsb(p);
    }
    return sum;
}

int main()
{
    int q;
    scd(n);
    scd(q);
    vll vec(n + 1);
    fenwick = vll(n + 1);
    frange(i, n)
    {
        sclld(vec[i + 1]);
    }

    frange(i, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int l, r;
            lli v;
            scd(l);
            scd(r);
            sclld(v);
            update(l, r, v);
        }
        else
        {
            int k;
            scd(k);
            printf("%lld\n", query(k) + vec[k]);
        }
    }
}