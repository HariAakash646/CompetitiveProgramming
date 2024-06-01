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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int bsze;

struct Query {
    int l, r, id;

    bool operator<(Query y) {
        if(l/bsze == y.l/bsze) return r < y.r;
        else return l/bsze < y.l/bsze;
    }
};

vi val, block;

void inline add(int id, int v) {
    block[id/bsze]+=v;
    val[id] += v;
}

int inline query(int l, int r) {
    int tot = 0;
    int i = l;
    for(; i%bsze&&i<=r; i++) {
        tot += val[i];
    }
    for(; i+bsze-1<=r; i+=bsze) {
        tot += block[i/bsze];
    }
    for(; i<=r; i++) {
        tot += val[i];
    }
    return tot;
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vi vec(n+1);
    frange(i, n) scd(vec[i+1]);

    vector<Query> quer(q);

    frange(i, q) {
        scd(quer[i].l);
        scd(quer[i].r);
        quer[i].id = i;
    }
    bsze = 1000;
    sort(all(quer));

    vi cnt(n+1);
    val=vi(n+1);
    block = vi(n+1);

    int l = 1;
    int r = 1;
    cnt[vec[l]]++;
    add(1, 1);
    add(0, n-1);
    int c = 1;
    int c2 = 0;
    vi out(q);
    for(auto p : quer) {
        while(l > p.l) {
            l--;
            add(cnt[vec[l]], -1);
            if(!cnt[vec[l]]) c++;
            cnt[vec[l]]++;
            if(cnt[vec[l]] == 2) c2++;
            add(cnt[vec[l]], 1);
        }
        while(r < p.r) {
            r++;
            add(cnt[vec[r]], -1);
            if(!cnt[vec[r]]) c++;
            cnt[vec[r]]++;
            if(cnt[vec[r]] == 2) c2++;
            add(cnt[vec[r]], 1);
        }
        while(l < p.l) {
            add(cnt[vec[l]], -1);
            cnt[vec[l]]--;
            if(!cnt[vec[l]]) c--;
            if(cnt[vec[l]] == 1) c2--;
            add(cnt[vec[l]], 1);
            l++;
        }
        while(r > p.r) {
            add(cnt[vec[r]], -1);
            cnt[vec[r]]--;
            if(!cnt[vec[r]]) c--;
            if(cnt[vec[r]] == 1) c2--;
            add(cnt[vec[r]], 1);
            r--;
        }
        int len = p.r - p.l + 1;
        // printf("%d %d %d %d\n", c, len, query(len/2, len/2), val[len/2]);
        if(len % 2 == 0) {
            if(query(len/2, len/2)) {
                if(c == 2) out[p.id] = 0;
                else out[p.id] = 1;
            } 
            else {
                if(query(len/2+1, n)) out[p.id] = 1;
                else {
                    out[p.id] = c2;
                }
            }
        }
        else {
            if(query(len/2+1, n)) out[p.id] = 1;
            else out[p.id] = c;
        }

    }
    for(auto e : out) printf("%d\n", e);
}