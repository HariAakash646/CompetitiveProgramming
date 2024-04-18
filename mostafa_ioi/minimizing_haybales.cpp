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

int n, k;

vvi act;
vi mav, miv;
vector<vb> vis;

void process(vi block, int id) {
    int ma = -1;
    int mi = 1e9;
    vi curr;
    frange(i, block.size()) {
        if(vis[id][i]) continue;
        int e = block[i];
        if(e >= ma - k && e <= mi + k) {
            curr.pb(e);
        }
        ma = max(ma, e);
        mi = min(mi, e);
    }
    sort(all(curr));
    act[id] = curr;
    mav[id] = ma;
    miv[id] = mi;
}

int main() {
    // usaco();
    
    scd(n);
    scd(k);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vvi block;
    vi curr;
    int sq = sqrt(n);

    frange(i, n) {
        curr.pb(vec[i]);
        if(curr.size() >= sq) {
            block.pb(curr);
            curr = {};
        }
    }
    if(curr.size()) {
        block.pb(curr);
    }

    act = vvi(block.size());
    mav = vi(block.size(), -1);
    miv = vi(block.size(), 1e9);
    vis = vector<vb>(block.size(), vb(sq));

    frange(i, block.size()) {
        process(block[i], i);
    }

    frange(i, n) {
        pii p = {1e9+10, 1e9};
        int mi = 1e9;
        int ma = 0;
        frange(i, block.size()) {
            auto it = lower_bound(all(act[i]), ma-k);
            if(it != act[i].end() && (*it) <= mi+k) {
                p = min(p, mp(*it, i));
            }
            mi = min(mi, miv[i]);
            ma = max(ma, mav[i]);
        }
        printf("%d\n", p.f);
        frange(i, block[p.s].size()) {
            if(vis[p.s][i]) continue;
            if(block[p.s][i] == p.f) {
                vis[p.s][i] = true;
                break;
            }
        }
        process(block[p.s], p.s);
    }


}