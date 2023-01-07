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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vii disjoint;
vi height;

bool cmp(const pii &x, const pii &y)
{
    return x.s < y.s;
}

int findf(int a)
{
    if (disjoint[a].f != a)
    {
        disjoint[a].f = findf(disjoint[a].f);
    }
    return disjoint[a].f;
}

void unionf(int a, int b, int rel)
{
    int roota = findf(a);
    int rootb = findf(b);
    int ha = height[roota];
    int hb = height[rootb];
    if (ha < hb)
    {
        disjoint[roota] = {rootb, rel};
        height[rootb]++;
    }
    else
    {
        disjoint[rootb] = {roota, rel};
        height[roota]++;
    }
}

int main()
{
    int n, q;
    disjoint = vii(n + 1);
    height = vi(n + 1);
    frange(i, n + 1)
    {
        disjoint[i] = {i, 1e9 + 5};
    }
    int a, b, r;
    frange(i, n - 1)
    {
        scd(a);
        scd(b);
        scd(r);
        unionf(a, b, r);
    }
    vector<set<pii, bool (*)(const pii &, const pii &)>> sets_vec(n + 1, set<pii, bool (*)(const pii &, const pii &)>(cmp));
    seti done;
    forr(i, 1, n + 1, 1)
    {
        int fo = findf(i);
        sets_vec[fo].insert({i, disjoint[i].s});
    }
    int k, v;
    frange(i, q)
    {
        scd(k);
        scd(v);
        int fo = findf(v);
        pii p1{v, k};
        pii p2{0, 1e9 + 6};
        set<pii, set<pii, bool (*)(const pii &, const pii &)>> arr(cmp) = sets_vec[fo];
        auto itr = arr.lower_bound(p1);
        auto itr1 = arr.lower_bound(p2);
        itr1--;
        printf("%d\n", itr1 - itr + 1);
    }
}