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
typedef vector<bool> vb;
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
    int st, n, m;
    scd(st);
    scd(n);
    scd(m);
    if (st == 4)
    {
        return 0;
    }
    else if (st == 1 || st == 2 || st == 3)
    {
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        frange(i, m)
        {
            int typ, l, r;
            scd(typ);
            scd(l);
            scd(r);
            if (typ == 1)
            {
                int v;
                scd(v);
                forr(i, l - 1, r) vec[i] = v;
            }
            else if (typ == 2)
            {
                int inv = 0;
                forr(i, l - 1, r - 1)
                {
                    forr(j, i + 1, r)
                    {
                        if (vec[i] > vec[j])
                            inv++;
                    }
                }
                printf("%d\n", inv);
            }
        }
    }
    else if (st == 5 || st == 6)
    {
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        vvi inv(n, vi(n));
        for (int i = n - 2; i >= 0; i--)
        {
            forr(j, i + 1, n)
            {
                if (j - i == 1)
                {
                    inv[i][j] = (vec[i] > vec[j]);
                    continue;
                }
                int a = 0;
                int b = 0;

                a = inv[i + 1][j];
                b = inv[i + 1][j - 1];
                inv[i][j] = inv[i][j - 1] + a - b + (vec[i] > vec[j]);
            }
        }
        frange(_, m)
        {
            int typ, l, r;
            scd(typ);
            scd(l);
            scd(r);
            printf("%d\n", inv[l - 1][r - 1]);
        }
    }
}