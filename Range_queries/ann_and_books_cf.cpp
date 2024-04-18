#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main()
{
    int n;
    lli k;
    scd(n);
    sclld(k);
    vll vec(n + 1);
    bsze = 2 * sqrt(n);
    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        if (a == 1)
            vec[i] = 1;
        else
            vec[i] = -1;
    }
    vll pref(n + 1);
    vll v1(n + 1), v2(n + 1), v3(n + 1);

    vll val(3 * (n + 1) + 1);
    map<lli, int> pos;
    pos[0] = 0;
    if (k)
    {
        pos[-k] = 1;
        pos[k] = 2;
        v2[0] = 1;
        v3[0] = 2;
    }
    forr(i, 1, n + 1)
    {
        lli a;
        sclld(a);
        vec[i] *= a;
        pref[i] = pref[i - 1] + vec[i];
        v1[i] = 3 * i;
        v2[i] = 3 * i + 1;
        v3[i] = 3 * i + 2;
        if (pos.find(pref[i]) != pos.end())
            v1[i] = pos[pref[i]];
        if (pos.find(pref[i] - k) != pos.end())
            v2[i] = pos[pref[i] - k];
        if (pos.find(k + pref[i]) != pos.end())
            v3[i] = pos[pref[i] + k];
        pos[pref[i]] = v1[i];
        pos[pref[i] - k] = v2[i];
        pos[pref[i] + k] = v3[i];
    }
    int q;
    scd(q);
    vector<Query> quer(q);

    frange(i, q)
    {
        scd(quer[i].l);
        scd(quer[i].r);
        quer[i].idx = i;
    }
    sort(all(quer));
    val[0]++;
    int l = 0;
    int r = 0;
    lli tot = 0;
    vll out(q);
    for (auto p : quer)
    {
        while (r < p.r)
        {
            r++;
            tot += val[v2[r]];
            val[v1[r]]++;
        }
        while (r > p.r)
        {
            val[v1[r]]--;
            tot -= val[v2[r]];
            r--;
        }
        while (l > p.l - 1)
        {
            l--;
            tot += val[v3[l]];
            val[v1[l]]++;
        }
        while (l < p.l - 1)
        {
            val[v1[l]]--;
            tot -= val[v3[l]];
            l++;
        }
        out[p.idx] = tot;
    }
    for (auto e : out)
        printf("%lld\n", e);
}