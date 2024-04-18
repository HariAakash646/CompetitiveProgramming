#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t);
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

void usaco() {
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
}

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int c, n, m, q;
vi v1, v2;

void solve() {
    vi og1 = v1;
    vi og2 = v2;
    if(v1[0] == v2[0]) {
        printf("0");
        return;
    }
    if(v1[0] > v2[0]) swap(v1, v2);
    int mi = v1[0];
    int ma = v2[0];
    
    stack<int> stk;
    int n = v1.size();
    int m = v2.size();

    if(v1[n-1] >= v2[m-1]) {
        v1 = og1;
        v2 = og2;
        printf("0");
        return;
    }
    // vi id1, id2;

    // for(int i=n-1; i>=0; i--) {
    //     if(stk.size() && v1[i] > v1[stk.top()]) continue;
    //     stk.push(i);
    // }
    // while(stk.size()) {
    //     id1.pb(stk.top());
    //     stk.pop();
    // }

    // for(int i=m-1; i>=0; i--) {
    //     if(stk.size() && v2[i] < v2[stk.top()]) continue;
    //     stk.push(i);
    // }
    // while(stk.size()) {
    //     id2.pb(stk.top());
    //     stk.pop();
    // }
    int id1 = min_element(all(v1)) - v1.begin();
    int id2 = max_element(all(v2)) - v2.begin();
    int i1 = 0;
    frange(i, id2+1) {
        while(i1 < id1 && v1[i1+1] < ma) {
            i1++;
            mi = min(mi, v1[i1]);
        }
        if(v2[i] <= mi) {
            v1 = og1;
            v2 = og2;
            printf("0");
            return;
        }
        ma = max(ma, v2[i]);
    }
    
    i1 = n-1;
    mi = v1[n-1];
    ma = v2[m-1];
    for(int i=m-1; i>=id2; i--) {
        while(i1 > id1 && v1[i1-1] < ma) {
            i1--;
            mi = min(mi, v1[i1]);
        }
        if(v2[i] <= mi) {
            v1 = og1;
            v2 = og2;
            printf("0");
            return;
        }
        ma = max(ma, v2[i]);
    }

    v1 = og1;
    v2 = og2;
    printf("1");
    
}

int main() {
    usaco();

    scd(c);
    scd(n);
    scd(m);
    scd(q);

    v1 = vi(n);
    v2 = vi(m);
    frange(i, n) scd(v1[i]);
    frange(i, m) scd(v2[i]);

    solve();

    frange(_, q) {
        int kx, ky;
        scd(kx);
        scd(ky);
        vi og1 = v1;
        vi og2 = v2;
        frange(i, kx) {
            int id, v;
            scd(id);
            scd(v);
            id--;
            v1[id] = v;
        }
        frange(i, ky) {
            int id, v;
            scd(id);
            scd(v);
            id--;
            v2[id] = v;
        }
        solve();
        v1 = og1;
        v2 = og2;
    }
}