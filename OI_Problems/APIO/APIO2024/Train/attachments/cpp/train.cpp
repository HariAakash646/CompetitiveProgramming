#include "train.h"
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

struct Node {
    int x, a, b;
    lli c;
};

long long solve(int n, int m, int w, std::vector<int> T, std::vector<int> X, std::vector<int> Y,
                std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> L,
                std::vector<int> R) {

    vector<map<int, vector<Node>>> graph(n);
    vvi arriv(n);
    arriv[0].pb(0);
    arriv[n-1].pb(1e9+1);
    vector<Node> nod(m);
    vector<vii> dep(n);
    frange(i, m) {
        int x = X[i];
        int y = Y[i];
        int a = A[i];
        int b = B[i];
        lli c = C[i];
        nod[i].x = y;
        nod[i].a = a;
        nod[i].b = b;
        nod[i].c = c;
        dep[x].pb(mp(a, i));
        arriv[y].pb(b);
    }
    forr(i, 0, n) {
        sort(all(arriv[i]));
        sort(all(dep[i]));
        int id = 0;
        int sz2 = dep[i].size();
        int sz = arriv[i].size();
        frange(j, sz) {
            while(id < sz2 && dep[i][id].f < arriv[i][j]) id++;
            while(id < sz2 && (j==sz-1 || dep[i][id].f < arriv[i][j+1])) {
                graph[i][arriv[i][j]].pb(nod[dep[i][id].s]);
                id++;
            }
            if(j < sz-1) {
                Node tmp;
                tmp.x = i;
                tmp.a = arriv[i][j+1] + 1;
                tmp.b = arriv[i][j+1];
                tmp.c = 0;
                graph[i][arriv[i][j]].pb(tmp);
            }
        }
    }    
    vii rgt(w), lft(w);
    set<pii> st;
    frange(i, w) {
        st.insert(mp(L[i], R[i]));
        rgt[i] = mp(R[i], i);
    }

    sort(all(rgt));
    vi pos(w);

    frange(i, w) {
        pos[rgt[i].s] = i;
        lft[i] = mp(L[i], i);
    }
    sort(all(lft));
    int id = 0;

    BIT<int> bit(w);
    forr(i, 1, w+1) bit.set(i, 1);

    vector<vector<map<int, lli>>> dist(2, vector<map<int, lli>>(n));
    vector<vector<map<int, bool>>> vis(2, vector<map<int, bool>>(n));
    dist[0][0][0] = 0;

    priority_queue<pair<int, pair<lli, pii>>, vector<pair<int, pair<lli, pii>>>, greater<pair<int, pair<lli, pii>>>> pq;
    pq.push(mp(0, mp(0, mp(0, 0))));
    while(pq.size()) {
        auto p = pq.top();
        pq.pop();
        int x = p.s.s.f;
        int ac = p.s.s.s;
        lli c = p.s.f;
        int ti = p.f;
        if(vis[0][x][ti]) continue;
        vis[0][x][ti] = true;
        printf("%d %d %lld\n", x, ti, c);

        while(id < w && lft[id].f <= ti) {
            bit.set(pos[lft[id].s]+1, 0);
            id++;
        }

        for(auto p : graph[x][ti]) {
            if(p.a < ti) continue;
            lli v = 0;

            if(p.a > p.b) {
                if(ac) {
                    auto it = lower_bound(all(rgt), mp(p.b, 0));
                    
                }
                
            }
            else {
                if(dist[p.x].find(p.b) == dist[p.x].end() || dist[p.x][p.b] > v * T[x] + p.c + c) {
                    dist[p.x][p.b] = v * T[x] + p.c + c;
                    pq.push(mp(p.b, mp(dist[p.x][p.b], p.x)));
                }
            }
        }
    }
    
    lli mi=-1;

    if(dist[n-1].find(1e9+1) != dist[n-1].end()) mi = dist[n-1][int(1e9+1)];

    return mi;
}
