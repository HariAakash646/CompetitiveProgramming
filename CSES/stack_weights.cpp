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

struct Data {
    lli v = 0;
    lli suma = 0;
    lli sumi = 0;
};

template <class T>
struct SegTree
{
    int size = 1, n;
    vector<T> segtree;
    vector<T> vec;


    void init(int l)
    {
        n = l;

        while (size < n)
            size *= 2;

        Data tmp;
        segtree.assign(2 * size, tmp);
        vec.assign(size, tmp);
    }

    T operation(T x, T y)
    {
        T out;
        out.v = x.v + y.v;
        out.suma = max(y.suma, x.suma + y.v);
        out.sumi = min(y.sumi, x.sumi + y.v);

        return out;
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

    // void set(int id, lli val)
    // {
    //     vec[id].v = val;

    // }

    void update(int x, int l, int r, int id, lli val)
    {
        if (l == r)
        {
            segtree[x].v = val;
            segtree[x].suma = max(0LL, val);
            segtree[x].sumi = min(0LL, val);
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

    void update(int id, lli val)
    {
        update(0, 0, size - 1, id, val);
    }

    T query(int x, int l, int r, int lx, int rx)
    {
        if (lx > r || rx < l)
        {
            Data tmp;
            return tmp;
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
    int n;
    scd(n);
    
    SegTree<Data> segtree;

    segtree.init(n);

    segtree.build();

    frange(i, n) {
        int a, b;
        scd(a);
        scd(b);
        a--;
        if(b == 1) segtree.update(a, 1);
        else segtree.update(a, -1);

        Data v = segtree.query(0, n-1);

        // printf("%lld %lld %lld ", v.suma, v.sumi, v.v);
        if(v.suma > 0 && v.sumi < 0) printf("?\n");
        else if(v.suma > 0) printf(">\n");
        else printf("<\n");  
    }


}