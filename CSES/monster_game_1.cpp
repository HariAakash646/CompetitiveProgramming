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

struct line {
    lli m, c;

    lli eval(lli x) {return m * x + c;}

    ld intersect(line l) {return ld(c - l.c) / ld(l.m - m);}
};

int main() {
    // usaco();
    int n, x;
    scd(n);
    scd(x);

    vector<pair<lli, lli>> vec(n);

    frange(i, n) sclld(vec[i].f);
    frange(i, n) sclld(vec[i].s);

    lli ma = 0;

    deque<line> dq;
    dq.pb({x, 0});

    for(auto p : vec) {
        while(dq.size() >= 2 && dq.front().eval(p.f) > dq[1].eval(p.f)) dq.pop_front();
        ma = dq[0].eval(p.f);
        line curr = {p.s, ma};

        while(dq.size() >= 2 && curr.intersect(dq[dq.size()-2]) <= dq[dq.size()-1].intersect(dq[dq.size()-2]))
            dq.pop_back();
        dq.pb(curr);
    }
    printf("%lld", ma);
}