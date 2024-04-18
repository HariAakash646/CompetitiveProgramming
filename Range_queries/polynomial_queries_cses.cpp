// Not working
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

int n, q;

int lsb(int pos)
{
    return pos & -pos;
}

void update(int pos, lli v, vll &fen)
{
    while (pos <= n)
    {
        fen[pos] += v;
        pos += lsb(pos);
    }
}

lli query(int pos, vll &fen)
{
    lli sum = 0;
    while (pos > 0)
    {
        sum += fen[pos];
        pos -= lsb(pos);
    }
    return sum;
}

int main()
{
    scd(n);
    scd(q);
    vll vec(n + 1);
    vll veca(n + 1);
    vll vecb(n + 1);

    forr(i, 1, n + 1)
    {
        sclld(vec[i]);
        veca[i] = vec[i] - vec[i - 1];
        vecb[i] = veca[i] - veca[i - 1];
    }
    vll fen1(n + 2);
    vll fen2(n + 2);
    vll fen3(n + 2);
    forr(i, 1, n + 1)
    {
        update(i, vecb[i], fen1);
        update(i, vecb[i] * (i - 1), fen2);
        update(i, vecb[i] * (i - 1) * (i - 1), fen3);
    }
    for (auto e : veca)
    {
        printf("%d ", e);
    }
    printf("\n");
    for (auto e : vecb)
    {
        printf("%d ", e);
    }
    printf("\n");
    for (auto e : fen1)
    {
        printf("%d ", e);
    }
    printf("\n");
    for (auto e : fen2)
    {
        printf("%d ", e);
    }
    printf("\n");
    for (auto e : fen3)
    {
        printf("%d ", e);
    }
    printf("\n");
    frange(_, q)
    {
        int typ;
        scd(typ);
        int l, r;
        scd(l);
        scd(r);
        if (typ == 2)
        {
            // lli t1 = query(r, fen1) * (r)-query(r, fen2);
            // lli t2 = query(l - 1, fen1) * (l - 1) - query(l - 1, fen2);
            lli t1 = (query(r, fen1) * r * r - r * query(r, fen2)) - (r * query(r, fen2) - query(r, fen3));
            l--;
            lli t2 = (query(l, fen1) * l * l - l * query(l, fen2)) - (l * query(l, fen2) - query(l, fen3)); // query(l - 1, fen1) * (l - 1) - query(l - 1, fen2);
            printf("%lld %lld %lld\n", t1, t2, t1 - t2);
        }
        else
        {
            update(l, 1, fen1);
            update(l, l - 1, fen2);
            update(l, (l - 1) * (l - 1), fen3);
            int v = (r - l + 1);
            update(r + 1, -v + 1, fen1);
            update(r + 1, (-v + 1) * (r), fen2);
            update(r + 1, (-v + 1) * r * r, fen3);
        }
    }
}