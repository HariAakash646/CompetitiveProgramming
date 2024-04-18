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

int bsze;

struct Query {
    int l, r;
    int id;

    bool operator<(Query other) {
        if(l/bsze == other.l/bsze) {
            return r < other.r;
        }
        else return l/bsze < other.l/bsze;
    }
};

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    vi vec(n);
    frange(i, n) scd(vec[i]);

    seti v2;
    for(auto e : vec) v2.insert(e);

    mpii pos;
    int c = 0;
    for(auto e : v2) {
        pos[e] = c++;
    }

    frange(i, n) {
        vec[i] = pos[vec[i]];
    }

    vi cnt(c);
    bsze = sqrt(n);
    vector<Query> quer(q);

    frange(i, q) {
        scd(quer[i].l);
        scd(quer[i].r);
        quer[i].l--;
        quer[i].r--;
        quer[i].id = i;
    }

    sort(all(quer));
    int l = 0;
    int r = 0;
    cnt[vec[l]]++;
    vi out(q);
    c = 0;
    for(auto p : quer) {
        while(l < p.l) {
            if(cnt[vec[l]] == 2) c--;
            cnt[vec[l]]--;
            if(cnt[vec[l]] == 2) c++;
            l++;
        }

        while(l > p.l) {
            l--;
            if(cnt[vec[l]] == 2) c--;
            cnt[vec[l]]++;
            if(cnt[vec[l]] == 2) c++;
        }

        while(r < p.r) {
            r++;
            if(cnt[vec[r]] == 2) c--;
            cnt[vec[r]]++;
            if(cnt[vec[r]] == 2) c++;
        }

        while(r > p.r) {
            if(cnt[vec[r]] == 2) c--;
            cnt[vec[r]]--;
            if(cnt[vec[r]] == 2) c++;
            r--;
        }
        out[p.id] = c;
    }
    for(auto e : out) printf("%d\n", e);
}