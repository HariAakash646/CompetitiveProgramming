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
 
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, v - vec[id]);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
            id += lsb(id);
        }
    }

    T query(int id)
    {
        T tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            id -= lsb(id);
        }
        return tot;
    }
};

vvi graph;
int timer=0;
vi st, en;

void dfs(int x, int p) {
    st[x] = ++timer;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
    en[x] = timer;
}

int bsze;

struct Query
{
    int l, r, idx;
    int l1, r1;
    bool operator<(Query other) const
    {
        return mp(l / bsze, r) <
               mp(other.l / bsze, other.r);
    }
};

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, q;
        scd(n);
        scd(q);

        graph = vvi(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }
        timer = 0;
        st = en = vi(n+1);
        dfs(1, 0);

        vi pos(n+1);
        forr(i, 1, n+1) {
            int x;
            scd(x);
            pos[x] = i;
        }

        vi val(n+1);
        forr(i, 1, n+1) {
            val[st[i]] = pos[i];
        }

        vector<Query> vec(q);
        bsze = sqrt(n);

        frange(i, q) {
            int l, r, x;
            scd(l);
            scd(r);
            scd(x);
            vec[i].l = st[x];
            vec[i].r = en[x];
            vec[i].l1 = l;
            vec[i].r1 = r;
            vec[i].idx = i;
        }

        sort(all(vec));


        int l = 1;
        int r = 1;

        vll va(n+1);
        vll pref(n+1);
        vector<pair<int, lli>> btc;

        va[val[1]] = 1;
        forr(i, 1, n+1) pref[i] = pref[i-1] + va[i];

        vb out(q);

        bsze = sqrt(n*sqrt(n));

        for(auto p : vec) {
            while(l < p.l) {
                btc.pb(mp(val[l], -1));
                va[val[l]] -= 1;
                l++;
            }
            while(l > p.l) {
                l--;
                btc.pb(mp(val[l], 1));
                va[val[l]] += 1;
            }
            while(r > p.r) {
                btc.pb(mp(val[r], -1));
                va[val[r]] -= 1;
                r--;
            }
            while(r < p.r) {
                r++;
                btc.pb(mp(val[r], 1));
                va[val[r]] += 1;
            }
            lli c = 0;
            if(btc.size() > bsze) {
                btc = {};
                forr(i, 1, n+1) pref[i] = pref[i-1] + va[i];
            }
            else {
                for(auto e : btc) {
                    if(p.l1 <= e.f && e.f <= p.r1) c += e.s;
                }
            }
            out[p.idx] = pref[p.r1] - pref[p.l1-1] + c;
        }
        for(auto e : out) {
            if(e) printf("YES\n");
            else printf("NO\n");
        }
        printf("\n");

    }
}