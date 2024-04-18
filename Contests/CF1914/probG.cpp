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

const lli mod = 998244353;

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;

    T def; // Assign a value

    void init(int l, T defv)
    {
        n = l;
        def = defv;

        while (size < n)
            size *= 2;

        segtree.assign(2 * size, def);
        vec.assign(size, def);
    }

    T operation(T x, T y)
    {
        return x + y; // Any required operation
    }

    void recalculate(int x)
    {
        segtree[x] = operation(segtree[2 * x + 1], segtree[2 * x + 2]);
    }

    void build(int x, int l, int r)
    {
        if (l == r)
        {
            segtree[x] = vec[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * x + 1, l, mid);
        build(2 * x + 2, mid + 1, r);
        recalculate(x);
    }

    void build()
    {
        build(0, 0, size - 1);
    }

    void set(int id, T val)
    {
        vec[id] = val;
    }

    void update(int x, int l, int r, int id, T val)
    {
        if (l == r)
        {
            segtree[x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (id <= mid)
        {
            update(2 * x + 1, l, mid, id, val);
        }
        else
        {
            update(2 * x + 2, mid + 1, r, id, val);
        }
        recalculate(x);
    }

    void update(int id, T val)
    {
        update(0, 0, size - 1, id, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            return def;
        }
        if (lx <= l && r <= rx)
        {
            return segtree[x];
        }
        int mid = (l + r) / 2;
        T v1 = query(2 * x + 1, l, mid, lx, rx);
        T v2 = query(2 * x + 2, mid + 1, r, lx, rx);
        return operation(v1, v2);
    }

    T query(int lx, int rx)
    {
        return query(0, 0, size - 1, lx, rx);
    }
};

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vi vec(2*n);
        vi st(n+1, -1), en(n+1, -1);
        frange(i, 2*n) {
            scd(vec[i]);
            if(st[vec[i]] == -1) st[vec[i]] = i;
            else en[vec[i]] = i;
        }

        seti stv;

        int l = 0;
        int c = 0;
        lli tot = 1;

        vb vis(n+1);
        SegTree<int> segtree;
        segtree.init(2*n, 0);
        segtree.build();

        frange(i, 2*n) {
            if(stv.find(vec[i]) == stv.end()) stv.insert(vec[i]);
            else stv.erase(vec[i]);
            // for(auto e : stv) printf("%d ", e);
            // printf("\n");
            if(stv.size() == 0) {
                c++;
                
                vis[vec[l]] = true;
                vis[vec[i]] = true;
                segtree.update(st[vec[i]], 1);
                segtree.update(en[vec[i]], 1);
                segtree.update(st[vec[l]], 1);
                segtree.update(en[vec[l]], 1);

                // seti pres;
                bool curr = false;
                forr(j, l, i+1) {
                    // if(vec[j] == vec[l] || vec[j] == vec[i]) {
                    //     curr = true;
                    //     for(auto e : st2) {
                    //         vis[e] = true;
                    //         segtree.update(st[e], 1);
                    //         segtree.update(en[e], 1);
                    //     }
                    // }
                    
                        // st2.insert(vec[j]);
                        vis[vec[j]] = segtree.query(st[vec[j]], en[vec[j]]);
                        if(vis[vec[j]]) {
                            segtree.update(st[vec[j]], 1);
                            segtree.update(en[vec[j]], 1);
                        }
                    
                    // else st2.erase(vec[j]);
                }

                for(int j=i; j>=l; j--) {
                    vis[vec[j]] = segtree.query(st[vec[j]], en[vec[j]]);
                        if(vis[vec[j]]) {
                            segtree.update(st[vec[j]], 1);
                            segtree.update(en[vec[j]], 1);
                        }
                }

                forr(j, l, i+1) {
                    // if(vec[j] == vec[l] || vec[j] == vec[i]) {
                    //     curr = true;
                    //     for(auto e : st2) {
                    //         vis[e] = true;
                    //         segtree.update(st[e], 1);
                    //         segtree.update(en[e], 1);
                    //     }
                    // }
                    
                        // st2.insert(vec[j]);
                        vis[vec[j]] = segtree.query(st[vec[j]], en[vec[j]]);
                        if(vis[vec[j]]) {
                            segtree.update(st[vec[j]], 1);
                            segtree.update(en[vec[j]], 1);
                        }
                    
                    // else st2.erase(vec[j]);
                }

                for(int j=i; j>=l; j--) {
                    vis[vec[j]] = segtree.query(st[vec[j]], en[vec[j]]);
                        if(vis[vec[j]]) {
                            segtree.update(st[vec[j]], 1);
                            segtree.update(en[vec[j]], 1);
                        }
                }

                // forr(j, l, i+1) {
                //     // if(vec[j] == vec[l] || vec[j] == vec[i]) {
                //     //     curr = true;
                //     //     for(auto e : st2) {
                //     //         vis[e] = true;
                //     //         segtree.update(st[e], 1);
                //     //         segtree.update(en[e], 1);
                //     //     }
                //     // }
                    
                //         // st2.insert(vec[j]);
                //         vis[vec[j]] = segtree.query(st[vec[j]], en[vec[j]]);
                //         if(vis[vec[j]]) {
                //             segtree.update(st[vec[j]], 1);
                //             segtree.update(en[vec[j]], 1);
                //         }
                    
                //     // else st2.erase(vec[j]);
                // }

                // for(int j=i; j>=l; j--) {
                //     vis[vec[j]] = segtree.query(st[vec[j]], en[vec[j]]);
                //         if(vis[vec[j]]) {
                //             segtree.update(st[vec[j]], 1);
                //             segtree.update(en[vec[j]], 1);
                //         }
                // }

                // st2 = {};
                // forr(j, l, i+1) {
                //     if(vis[vec[j]]) st2.insert(vec[j]);
                // }

                tot *= (lli)segtree.query(l, i);
                tot %= mod;
                l = i+1;
                
            }
        }
        printf("%d %lld\n", c, tot);
    }
}