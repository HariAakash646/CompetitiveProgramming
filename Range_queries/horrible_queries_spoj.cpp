#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
typedef long long int lli;
typedef vector<lli> vll;

int n, c;
vll fen1;
vll fen2;

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
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        scd(c);

        fen1 = vll(n + 2);
        fen2 = vll(n + 2);

        frange(i, c)
        {
            int typ;
            scd(typ);
            int l, r;
            scd(l);
            scd(r);
            if (typ)
            {
                lli t1 = query(r, fen1) * (r)-query(r, fen2);
                lli t2 = query(l - 1, fen1) * (l - 1) - query(l - 1, fen2);
                printf("%lld\n", t1 - t2);
            }
            else
            {
                lli v;
                sclld(v);
                update(l, v, fen1);
                update(l, v * (l - 1), fen2);
                update(r + 1, -v, fen1);
                update(r + 1, -v * (r), fen2);
            }
        }
    }
}