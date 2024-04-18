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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int bsze;

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return mp(l / bsze, r) <
               mp(other.l / bsze, other.r);
    }
};

int main()
{
    int n;
    scd(n);
    vi vec(n);
    vi cnt(1e6 + 1);
    frange(i, n) { scd(vec[i]); }
    int q;
    scd(q);
    vector<Query> quer(q);
    frange(i, q)
    {
        quer[i].idx = i;
        scd(quer[i].l);
        quer[i].l--;
        scd(quer[i].r);
        quer[i].r--;
    }
    bsze = sqrt(n);
    sort(all(quer));
    vi out(q);
    int cl = 0;
    int cr = -1;
    int c = 0;
    for (auto e : quer)
    {
        while (cr < e.r)
        {
            cr++;
            if (cnt[vec[cr]] == 0)
                c++;
            cnt[vec[cr]]++;
        }
        while (cl < e.l)
        {
            cnt[vec[cl]]--;
            if (cnt[vec[cl]] == 0)
                c--;
            cl++;
        }
        while (cr > e.r)
        {
            cnt[vec[cr]]--;
            if (cnt[vec[cr]] == 0)
                c--;
            cr--;
        }
        while (cl > e.l)
        {
            cl--;
            if (cnt[vec[cl]] == 0)
                c++;
            cnt[vec[cl]]++;
        }
        out[e.idx] = c;
    }
    for (auto e : out)
        printf("%d\n", e);
}
