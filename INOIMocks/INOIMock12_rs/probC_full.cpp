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
typedef long double ld;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

struct line {
    lli m=0, c=1e16;

    lli eval(lli x) {
        return m*x + c;
    }

    ld intersect(line y) {
        return ld(y.c - c) / ld(m - y.m);
    }
};

struct Data {
    line ln;
    int lc = -1;
    int rc = -1;
};

const int maxn = 2e5 + 10;
Data tree[maxn * 4];
int id = 0;

void add(Data data, int x, lli l, lli r) {
    if(l > r) return;
    lli mid = (l+r)/2;
    bool lb = data.ln.eval(l) < tree[x].ln.eval(l);
    bool mb = data.ln.eval(mid) < tree[x].ln.eval(mid);
    if(mb) {
        swap(data.ln, tree[x].ln);
    } 
    if(lb != mb) {
        if(tree[x].lc == -1) {
            tree[x].lc = ++id;
            tree[id] = data;
        }
        else {
            add(data, tree[x].lc, l, mid-1);
        }
    }
    else {
        if(tree[x].rc == -1) {
            tree[x].rc = ++id;
            tree[id] = data;
        }
        else {
            add(data, tree[x].rc, mid+1, r);
        }
    }
}

lli get(int x, lli l, lli r, lli val) {
    lli mid = (l + r)/2;    
    // printf("%lld ", tree[x].ln.m);
    if(val == mid) return tree[x].ln.eval(val);
    if(val < mid) {
        if(tree[x].lc != -1)
            return min(tree[x].ln.eval(val), get(tree[x].lc, l, mid-1, val));
        else 
            return tree[x].ln.eval(val);
    }
    else {
        if(tree[x].rc != -1)
            return min(tree[x].ln.eval(val), get(tree[x].rc, mid+1, r, val));
        else 
            return tree[x].ln.eval(val);
    }
}

int main() {
    // usaco();
    int n;
    scd(n);

    vector<pair<lli, lli>> vec(n);

    frange(i, n) {
        sclld(vec[i].f);
    }
    frange(i, n) {
        sclld(vec[i].s);
    }
    lli val = 0;
    Data tmp;
    tmp.ln.m = -2 * vec[0].f;
    tmp.ln.c = vec[0].f * vec[0].f - vec[0].s;
    add(tmp, 0, 0, 1e6+10);
    forr(i, 1, n) {
        // printf("%d ", i);
        lli data = get(0, 0, 1e6+10, vec[i].f);
        // printf("\n");
        val = data + vec[i].f * vec[i].f - vec[i].s;
        tmp.ln.m = -2 * vec[i].f;
        tmp.ln.c = val + vec[i].f * vec[i].f;
        // printf("%lld %lld\n", tmp.ln.m, tmp.ln.c);
        add(tmp, 0, 0, 1e6+10);
    }

    frange(i, n) {
        val += vec[i].s;
    }

    printf("%lld", val);
}