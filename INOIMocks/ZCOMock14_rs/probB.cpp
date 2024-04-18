#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

struct Segtree {
    vll segtree;
    vector<pair<lli, lli>> lazy;
    int n, size = 1;
    lli rt;

    void init(int l, int rtm) {
        n = l;
        size = 1;
        rt = rtm;
        while(size < n) size *= 2;
        segtree = vll(2*size);
        lazy = vector<pair<lli, lli>>(2*size);
    }

    void recalculate(int x) {
        segtree[x] = segtree[2*x+1]+ segtree[2*x+2];
    }

    void propagate(int x, int l, int r) {
        segtree[x] +=  (lli(r - l+ 1) * (2*lazy[x].f + (r-l) * rt * lazy[x].s)) / 2;
        if(l != r) {
            int mid = (l+r)/2;
            lazy[2*x+1].f += lazy[x].f;
            lazy[2*x+1].s += lazy[x].s;
            lazy[2*x+2].f += lazy[x].f + rt * lazy[x].s * (mid - l + 1);
            lazy[2*x+2].s += lazy[x].s;
        }
        lazy[x] = mp(0, 0);
    }

    void update(int x, int l, int r, int lx, int rx, lli v) {
        if(rx < l || lx > r) return;
        propagate(x, l, r);
        if(lx <= l && r <= rx) {
            lazy[x].f += v;
            lazy[x].s += 1;
            return;
        }
        int mid = (l+r)/2;
        if(lx <= mid)
            update(2*x+1, l, mid, lx, rx, v);
        if(rx >= mid+1)
            update(2*x+2, mid+1, r, lx, rx, v+max(0, (mid-max(lx, l)+1)) * rt);
        propagate(2*x+1, l, mid);
        propagate(2*x+2, mid+1, r); 
        recalculate(x);
    }

    lli query(int x, int l, int r, int lx, int rx) {
        if(rx < l || lx > r) return 0;
        propagate(x, l, r);
        if(lx <= l && r <= rx) {
            return segtree[x];
        }
        int mid = (l+r)/2;
        lli v1 = query(2*x+1, l, mid, lx, rx);
        lli v2 = query(2*x+2, mid+1, r, lx, rx);
        return v1+ v2;
    }

    void update(int lx, int rx, lli v) {
        if(lx > rx) return;
        update(0, 0, size-1, lx, rx, v);
    }

    lli query(int lx, int rx) {
        return query(0, 0, size-1, lx, rx);
    }
};

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    lli ma2 = 0;

    vector<pair<pii, pii>> vecx(k), vecy(k);
    lli tot = 0;
    frange(i, k) {
        int x1, y1, x2, y2;
        scd(x1);
        scd(y1);
        scd(x2);
        scd(y2);
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        vecx[i] = mp(mp(x1, y1), mp(x2, y2));
        vecy[i] = mp(mp(y1, x1), mp(y2, x2));
        tot += x2 - x1 + y2 - y1;
        ma2 += x2 - x1;
    }

    sort(all(vecx));
    sort(all(vecy));

    Segtree seg1, seg2, seg3;
    seg1.init(m+1, 4);
    seg2.init(m+1, 0);
    seg3.init(m+1, -4);

    for(auto p : vecx) {
        int x = (p.s.f - p.f.f) / 4;
        seg2.update(p.f.s-x, p.s.s+x, p.s.f - p.f.f);
        seg3.update(max(1, p.f.s-x), p.f.s, (p.f.s-max(1, p.f.s-x)) * 4);
        seg1.update(p.s.s, min(m, p.s.s+x), 0);
    }
    lli ma = 0;

    forr(i, 1, m+1) ma = max(ma, seg2.query(i, i) - seg1.query(i, i) - seg3.query(i, i));

    // forr(i, 1, m+1) {
    //     printf("%lld %lld %lld\n", seg2.query(i, i), seg1.query(i, i), seg3.query(i, i));
    // }

    // printf("%lld ", ma);

    printf("%lld", 2*tot - ma);
}