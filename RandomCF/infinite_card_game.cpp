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

vii mono, bi;
vi out;

int dfs(int x, pii p) {
    if(x != (int)out.size() - 1 && out[x]) return out[x];
    out[x] = 1;
    auto it = lower_bound(all(bi), mp(p.s+1, 0));
    if(it == bi.end()) {
        out[x] = 2;
    }
    else {

        auto it1 = lower_bound(all(mono), mp((*it).s+1, 0));
        if(it1==mono.end()) out[x] = -1;
        else
            out[x] = dfs(it1-mono.begin(), *it1);
    }
    return out[x];
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vii vec(n);
        frange(i, n) scd(vec[i].f);
        frange(i, n) scd(vec[i].s);
        sort(all(vec));

        vii mono2 = vec;

        vii vt;

        for(auto p : vec) {
            while(vt.size() && vt.back().s <= p.s) vt.pop_back();
            vt.pb(p);
        }
        mono = vt;
        sort(all(mono));

        scd(n);
        vec=vii(n);
        frange(i, n) scd(vec[i].f);
        frange(i, n) scd(vec[i].s);
        sort(all(vec));
        vt = {};

        for(auto p : vec) {
            while(vt.size() && vt.back().s <= p.s) vt.pop_back();
            vt.pb(p);
        }

        bi = vt;

        sort(all(bi));

        out=vi(mono.size()+1);

        int c2=0, c1=0, c0=0;

        for(auto p : mono2) {
            int v = dfs((int)out.size()-1, p);
            if(v==2) c2++;
            else if(v==1) c1++;
            else c0++;
        }
        printf("%d %d %d\n", c2, c1, c0);
    }
}