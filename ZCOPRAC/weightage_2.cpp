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

struct line {
    lli m, c;
    vi id;

    lli eval(lli x) {return m * x + c;}

    ld intersect(line l) {return ld(c - l.c) / ld(l.m - m);}
};

bool cmp(pair<pii, int> x, pair<pii, int> y) {
    return x.f.f - x.f.s < y.f.f - y.f.s;
}

int main() {
    // usaco();
    int n, p;
    scd(n);
    scd(p);

    vector<pair<pii, int>> vec(n);
    frange(i, n) {
        scd(vec[i].f.f);
        scd(vec[i].f.s);
        vec[i].s = i+1;
    }

    sort(all(vec), cmp);

    deque<line> dq;


    for(auto p : vec) {
        line curr = {p.f.f - p.f.s, 100 * p.f.s};
        curr.id = {p.s};
        // printf("%lld %lld ", curr.m, curr.c);
        // if(dq.size())
        // cout << curr.intersect(dq.back());
        // cout << "\n";
        while(dq.size() && dq.back().m == curr.m && dq.back().c < curr.c) dq.pop_back();
        if(dq.size() && mp(curr.m, curr.c) == mp(dq.back().m, dq.back().c)) {dq.back().id.pb(p.s); continue;}
        if(dq.size() && curr.m == dq.back().m) continue;
        while(dq.size() >= 2 && curr.intersect(dq[dq.size()-2]) < dq[dq.size()-2].intersect(dq[dq.size()-1])) dq.pop_back();
        
        
        if(dq.size() == 0 || dq.back().m != curr.m)
            dq.pb(curr);
    }

    while(dq.size() >= 2 && dq[0].eval(0) < dq[1].eval(0)) dq.pop_front();
    while(dq.size() >= 2 && dq.back().eval(100) < dq[dq.size()-2].eval(100)) dq.pop_back();

    printf("%d\n", (int)dq.size());
    vi out;
    for(auto p : dq) for(auto e : p.id) out.pb(e);
    sort(all(out));
    for(auto e : out) printf("%d ", e);
}