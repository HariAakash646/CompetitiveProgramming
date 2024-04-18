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

int mod = 998244353;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        int ma = 0, sma = 0;
        for (auto e : vec)
        {
            if (e >= ma)
            {
                sma = ma;
                ma = e;
            }
            else if (e > sma)
            {
                sma = e;
            }
        }
        lli out = 1;
        if (ma - sma > 1)
        {
            out = 0;
        }
        else if (ma == sma)
        {
            forr(i, 2, n + 1)
            {
                out *= i;
                out %= mod;
            }
        }
        else
        {
            int k = 0;
            for (auto e : vec)
            {
                if (e == sma)
                    k++;
            }
            lli sub = 1;
            forr(i, 2, n + 1)
            {
                out *= i;
                out %= mod;
                if (i != k + 1)
                {
                    sub *= i;
                    sub %= mod;
                }
            }
            out -= sub;
            out += mod;
            out %= mod;
        }
        printf("%lld\n", out);
    }
}