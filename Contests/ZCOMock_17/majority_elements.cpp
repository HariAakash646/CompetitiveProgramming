#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

unordered_set<int, custom_hash> val[100001];

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int n, q;
    cin >> n >> q;

    vi vec(n);
    frange(i, n)
            cin >>
        vec[i];

    vector<Query> quer(q);

    // vector<vi> pref(101, vi(n + 1));

    // forr(i, 1, 101)
    // {
    //     forr(j, 1, n + 1)
    //     {
    //         pref[i][j] = pref[i][j - 1] + (vec[j - 1] == i);
    //     }
    // }
    vec.pb(1e9);
    vector<int> pos;
    pos.pb(0);

    forr(i, 1, n)
    {
        if (vec[i] != vec[i - 1])
            pos.pb(i);
    }
    pos.pb(n);
    frange(i, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int mid = (l + r) / 2;
        int v = vec[mid];
        int it1 = lower_bound(all(vec), v) - vec.begin();
        int it2 = upper_bound(all(vec), v) - vec.begin();
        it2--;
        it1 = max(l, it1);
        it2 = min(r, it2);
        int x = it2 - it1 + 1;
        // printf("%d ", x);
        if (2 * x > (r - l + 1))
            printf("%d\n", v);
        else
            printf("-1\n");
    }
    // bsze = sqrt(n);
    // sort(all(quer));
    // vi cnt(n + 1);

    // int l = 0;
    // int r = 0;

    // cnt[vec[0]]++;

    // int ma = 1;

    // forr(i, 1, n)
    // {
    //     val[0].insert(vec[i]);
    // }
    // val[1].insert(vec[0]);
    // vi out(q);
    // for (auto p : quer)
    // {
    //     while (r < p.r)
    //     {
    //         r++;
    //         val[cnt[vec[r]]].erase(vec[r]);
    //         cnt[vec[r]]++;
    //         val[cnt[vec[r]]].insert(vec[r]);

    //         if (cnt[vec[r]] > ma)
    //         {
    //             ma = cnt[vec[r]];
    //         }
    //     }
    //     while (l < p.l)
    //     {
    //         val[cnt[vec[l]]].erase(vec[l]);
    //         // printf("%d\n", cnt[vec[l]]);
    //         if (cnt[vec[l]] == ma)
    //         {
    //             if (val[cnt[vec[l]]].size() == 0)
    //                 ma--;
    //         }
    //         cnt[vec[l]]--;
    //         val[cnt[vec[l]]].insert(vec[l]);
    //         l++;
    //     }
    //     // printf("%d %d %d %d\n", l, r, ma, mv);

    //     while (r > p.r)
    //     {
    //         val[cnt[vec[r]]].erase(vec[r]);
    //         if (cnt[vec[r]] == ma)
    //         {
    //             if (val[cnt[vec[r]]].size() == 0)
    //                 ma--;
    //         }
    //         cnt[vec[r]]--;
    //         val[cnt[vec[r]]].insert(vec[r]);
    //         r--;
    //     }
    //     // printf("%d %d %d %d\n", l, r, ma, mv);

    //     // printf("%d %d %d %d\n", l, r, ma, mv);

    //     while (l > p.l)
    //     {
    //         l--;
    //         val[cnt[vec[l]]].erase(vec[l]);
    //         cnt[vec[l]]++;
    //         val[cnt[vec[l]]].insert(vec[l]);

    //         if (cnt[vec[l]] > ma)
    //         {
    //             ma = cnt[vec[l]];
    //         }
    //     }
    //     // printf("%d %d %d %d\n", l, r, ma, mv);

    //     if (2 * ma > (p.r - p.l + 1))
    //     {
    //         out[p.idx] = *val[ma].begin();
    //     }
    //     else
    //         out[p.idx] = -1;
    // }

    // for (auto e : out)
    //     cout << e << "\n";
}