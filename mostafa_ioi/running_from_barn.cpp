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

BIT<lli> bit(0);
vvi lift;
vector<vll> liftv;
vvi graph;
int timer = 0;
vi st, en;
lli l;

void dfs(int x) {
    st[x] = ++timer;
    for(auto e : graph[x]) {
        dfs(e);
    }
    en[x] = timer;
}

int binlift(int x) {
    lli tot = 0;
    for(int i=19; i>=0; i--) {
        lli vt = tot + liftv[i][x];
        int xt = lift[i][x];
        if(vt <= l) {
            tot = vt;
            x = xt;
        }
    }
    return lift[0][x];
}

vi out;
vi rem;

void dfs2(int x) {
    out[x] = rem[x]+1;
    for(auto e : graph[x]) {
        dfs2(e);
        out[x] += out[e];
    }
    
}

int main() {
    // usaco();
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
    int n; 
    scd(n);
    sclld(l);

    lift = vvi(20, vi(n+1));
    liftv = vector<vll>(20, vll(n+1));

    liftv[0][1] = 1e18;
    graph = vvi(n+1);

    forr(i, 2, n+1) {
        int p;
        lli v;
        scd(p);
        sclld(v);
        lift[0][i] = p;
        liftv[0][i] = v;
        graph[p].pb(i);
    }

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
            liftv[i][j] = liftv[i-1][j] + liftv[i-1][lift[i-1][j]];
        } 
    }

    st = en = vi(n+1);
    dfs(1);

    // bit = BIT<lli>(n);
    rem = vi(n+1);
    forr(i, 1, n+1) {
        int x = binlift(i);
        rem[x]--;
        // bit.add(st[x], 1);
    }

    out = vi(n+1);
    dfs2(1);
    forr(i, 1, n+1) printf("%d\n", out[i]);


}