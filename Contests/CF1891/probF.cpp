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

int n;
vvi graph;
vi st, en;
int timer;

void dfs(int x, int p) {
    st[x] = ++timer;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
        }
    }
    en[x] = timer;
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


int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int q;
        scd(q);
        timer = 0;
        n = 1;
        graph = vvi(q+2);

        vii vec(q, mp(0, -2e9));

        frange(i, q) {
            int k;
            scd(k);
            if(k == 1) {
                int v;
                scd(v);
                n++;
                graph[v].pb(n);
                graph[n].pb(v);
                vec[i].f = n;
            }
            else {
                int v, x;
                scd(v);
                scd(x);
                vec[i] = mp(v, x);
            }
        }   

        st = en = vi(n+1);
        dfs(1, 0);

        vi en2(n+1);
        forr(i, 1, n+1) en2[i] = st[i];

        BIT<lli> bit(timer+10);
        vll val(n+1);
        for(auto p : vec) {
            if(p.s == -2e9) val[p.f] = -bit.query(st[p.f]);
            else {
                bit.add(st[p.f], p.s);
                bit.add(en[p.f]+1, -p.s);
            }
        }

        forr(i, 1, n+1) {

            printf("%lld ", bit.query(st[i])+  val[i]);
        }
        printf("\n");

    }
}