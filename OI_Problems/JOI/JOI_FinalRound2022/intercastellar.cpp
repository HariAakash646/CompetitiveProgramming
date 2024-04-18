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
    int n;
    scd(n);
    vi vec(n);
    vector<pair<int, lli>> posv(n);
    frange(i, n)
    {
        scd(vec[i]);
        int c = 0;
        while (vec[i] % 2 == 0)
        {
            vec[i] /= 2;
            c++;
        }
        posv[i] = {vec[i], 1 << c};
    }
    map<pair<lli, lli>, int> quer;
    lli st = 0;
    for (auto p : posv)
    {
        quer[mp(st, st + p.s - 1)] = p.f;
        st += p.s;
    }
    int q;
    scd(q);
    frange(_, q)
    {
        lli x;
        sclld(x);
        x--;
        auto it = quer.upper_bound(mp(x, 1e16));
        it--;
        printf("%d\n", (*it).s);
    }
    // for (auto p : quer)
    // {
    //     // forr(i, p.f.f, p.f.s + 1)
    //     // {
    //     //     printf("%d ", p.s);
    //     // }
    //     printf("%lld %lld %d\n", p.f.f, p.f.s, p.s);
    // }
}