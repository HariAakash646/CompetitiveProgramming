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
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

const int MAXN = 1e5 + 5;
vector<int> tree1[4*MAXN], tree2[4*MAXN];
vii vec;

void build(int x, int l, int r) {
    if(l == r) {
        // printf("%d %d\n", x, l);
        tree1[x].pb(vec[l].s);
        tree2[x].pb(vec[l].f + vec[l].s);

        return; 
    }
    int mid = (l+r)/2;
    build(2*x+1, l, mid);
    build(2*x+2, mid+1, r);
    merge(all(tree1[2*x+1]), all(tree1[2*x+2]), back_inserter(tree1[x]));
    merge(all(tree2[2*x+1]), all(tree2[2*x+2]), back_inserter(tree2[x]));
}

int query1(int x, int l, int r, int lx, int rx, int v) {
    if(l > rx || r < lx) return 0;
    if(lx <= l && r <= rx) {
        return tree1[x].end() - lower_bound(all(tree1[x]), v);
    }
    int mid = (l+r)/2;
    return query1(2*x+1, l, mid, lx, rx, v) + query1(2*x+2, mid+1, r, lx, rx, v);
}

int query2(int x, int l, int r, int lx, int rx, int v) {
    if(l > rx || r < lx) return 0;
    if(lx <= l && r <= rx) {
        return tree2[x].end() - lower_bound(all(tree2[x]), v);
    }
    int mid = (l+r)/2;
    return query2(2*x+1, l, mid, lx, rx, v) + query2(2*x+2, mid+1, r, lx, rx, v);
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vec = vii(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    sort(all(vec));
    build(0, 0, n-1);

    frange(_, q) {
        int x, y, z;
        scd(x);
        scd(y);
        scd(z);
        int d = z - y;
        int out = 0;
        if(d >= x) {
            int l = lower_bound(all(vec), mp(x, 0)) - vec.begin();
            int r = lower_bound(all(vec), mp(d+1, 0)) - vec.begin() - 1;
            out += query2(0, 0, n-1, l, r, z);
            x = d+1;
        }
        int l = lower_bound(all(vec), mp(x, 0)) - vec.begin();
        // int r = lower_bound(all(vec), mp(d+1, 0)) - vec.begin() - 1;
        out += query1(0, 0, n-1, l, n-1, y);
        printf("%d\n", out);
    }

}