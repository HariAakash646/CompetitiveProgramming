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

int bsze;

struct Query
{
    int l, r, idx;
    bool operator<(Query other)
    {
        return mp(l / bsze, r) <
               mp(other.l / bsze, other.r);
    }
};

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vi vec(n + 1);
    vi pref(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
        pref[i] = pref[i - 1] ^ vec[i];
    }
    vector<Query> query(m);
    frange(i, m)
    {
        scd(query[i].l);
        scd(query[i].r);
        query[i].idx = i;
    }
    bsze = sqrt(n);
    sort(all(query));
    int l = 0;
    int r = 0;
    vi cnt(1 << 20);
    cnt[0]++;
    lli c = 0;
    vll out(m);
    for (auto e : query)
    {
        while (r > e.r)
        {
            cnt[pref[r]]--;
            c -= cnt[pref[r] ^ k];
            r--;
        }
        while (r < e.r)
        {
            r++;
            c += cnt[pref[r] ^ k];
            cnt[pref[r]]++;
        }
        while (l < e.l - 1)
        {
            cnt[pref[l]]--;
            c -= cnt[pref[l] ^ k];
            l++;
        }
        while (l > e.l - 1)
        {
            l--;
            c += cnt[pref[l] ^ k];
            cnt[pref[l]]++;
        }

        // cnt[pref[e.l - 1]]++;
        out[e.idx] = c;
    }
    for (auto e : out)
        printf("%lld\n", e);
}