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


int n;
vvi graph;
int timer = 0;
vi st, en, sze;

void dfs(int x, int p) {
    st[x] = ++timer;
    sze[x] = 1;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            sze[x] += sze[e];
        }
    }
    en[x] = ++timer;
}

int main() {
    // usaco();
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
    int q;
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

    sze = st = en = vi(n+1);
    dfs(1, 0);

    BIT<lli> bit(timer);
    BIT<lli> bit2(timer);
    vector<set<pii>> col(1e5+1);

    frange(_, q) {
        int t;
        scd(t);

        if(t == 1) {
            int x, c;
            scd(x);
            scd(c);
            auto it = col[c].upper_bound(mp(st[x], 1e9));
            if(it != col[c].begin()) {
                it--;
                pii p = *it;
                if(p.f <= st[x] && st[x] <= en[p.s]) continue;
            }
            it = col[c].lower_bound(mp(st[x], 0));
            set<pii> er;
            while(it != col[c].end() && en[(*it).s] <= en[x]) {
                auto p = *it;
                bit.add(p.f, -1);
                bit.add(en[p.s], 1);
                bit2.add(p.f, -sze[p.s]);
                er.insert(p);
                it++;
            }
            for(auto p : er) col[c].erase(p);
            bit.add(st[x], 1);
            bit.add(en[x], -1);
            bit2.add(st[x], sze[x]);
            col[c].insert(mp(st[x], x));
        }
        else {
            int x;
            scd(x);
            lli tot = bit.query(st[x])*sze[x] + bit2.query(en[x]) - bit2.query(st[x]);
            printf("%lld\n", tot);
        }
    }

}