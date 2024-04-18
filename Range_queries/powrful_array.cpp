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
    int n, t;
    scd(n);
    scd(t);
    vll vec(n);
    frange(i, n) sclld(vec[i]);
    vector<Query> quer(t);
    frange(i, t)
    {
        quer[i].idx = i;
        scd(quer[i].l);
        scd(quer[i].r);
        quer[i].l--;
        quer[i].r--;
    }
    bsze = sqrt(n);
    sort(all(quer));
    vll out(t);
    vll cnt(1e6 + 1);
    int cl = 0;
    int cr = -1;
    lli tot = 0;
    for (auto e : quer)
    {
        while (cr < e.r)
        {
            cr++;
            tot -= cnt[vec[cr]] * cnt[vec[cr]] * vec[cr];
            cnt[vec[cr]]++;
            tot += cnt[vec[cr]] * cnt[vec[cr]] * vec[cr];
        }
        while (cl < e.l)
        {
            tot -= cnt[vec[cl]] * cnt[vec[cl]] * vec[cl];
            cnt[vec[cl]]--;
            tot += cnt[vec[cl]] * cnt[vec[cl]] * vec[cl];
            cl++;
        }
        while (cr > e.r)
        {
            tot -= cnt[vec[cr]] * cnt[vec[cr]] * vec[cr];
            cnt[vec[cr]]--;
            tot += cnt[vec[cr]] * cnt[vec[cr]] * vec[cr];
            cr--;
        }
        while (cl > e.l)
        {
            cl--;
            tot -= cnt[vec[cl]] * cnt[vec[cl]] * vec[cl];
            cnt[vec[cl]]++;
            tot += cnt[vec[cl]] * cnt[vec[cl]] * vec[cl];
        }
        out[e.idx] = tot;
    }
    for (auto e : out)
        printf("%lld\n", e);
}