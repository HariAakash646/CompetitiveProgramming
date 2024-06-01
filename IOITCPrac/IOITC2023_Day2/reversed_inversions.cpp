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

int bsze=0;

struct Query {
    int l, r, id;

    bool operator<(Query y) {
        if(l /bsze == y.l / bsze) return r < y.r;
        else return l/bsze < y.l/bsze;
    }
};

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    bsze = sqrt(n);

    vi vec(n+1);
    forr(i, 1, n+1) scd(vec[i]);

    vector<Query> quer(q);
    frange(i, q) {
        scd(quer[i].l);
        scd(quer[i].r);
        quer[i].id = i;
    }
    sort(all(quer));

    int l = 1, r = 1;
    vi cnt(n+1);
    cnt[vec[1]]++;

    lli tot = 0;

    vll out(q);

    for(auto p : quer) {
        while(l > p.l) {
            l--;
            tot -= cnt[vec[l]];
            cnt[vec[l]]++;
        }
        while(r < p.r) {
            r++;
            tot -= cnt[vec[r]];
            cnt[vec[r]]++;
        }
        while(l<p.l) {
            cnt[vec[l]]--;
            tot += cnt[vec[l]];
            l++;
        }
        while(r > p.r) {
            cnt[vec[r]]--;
            tot += cnt[vec[r]];
            r--;
        }
        lli c = (p.r - p.l + 1);
        out[p.id] = c * (c-1)/2 + tot;
    }
    for(auto e : out) printf("%lld\n", e);
}