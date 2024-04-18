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

int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n;
    scd(c);
    scd(n);
    multiset<int> chick;
    frange(i, c)
    {
        int t;
        scd(t);
        chick.insert(t);
    }
    vii cow(n);
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        cow[i] = {b, a};
    }
    sort(all(cow));
    int out = 0;
    for (auto p : cow)
    {
        auto itr = chick.lower_bound(p.s);
        if (itr == chick.end())
            continue;
        if (*itr <= p.f)
        {
            out++;
            chick.erase(itr);
        }
    }
    printf("%d", out);
}