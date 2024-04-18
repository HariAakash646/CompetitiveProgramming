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

    lli eval(lli x) {return m * x + c;}

    ld intersect(line l) {return ld(c - l.c) / ld(l.m - m);}
};

int main() {
    // usaco();
    int n;
    scd(n);
    vii vec(n);
    vll dist(n+1);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);

        if(i > 0) {
            dist[i] = dist[i-1] + vec[i-1].s;
        }
    }

    dist[n] = dist[n-1] + vec[n-1].s;

    vll pref(n);
    pref[0] = vec[0].f;

    forr(i, 1, n) pref[i] = pref[i-1] + vec[i].f;

    vll val(n);

    val[0] = pref[0] * vec[0].s;

    forr(i, 1, n) {
        val[i] = val[i-1] + pref[i] * vec[i].s;
    }

    deque<line> dq;
    line curr = {0, 0};
    dq.pb(curr);

    lli ans = 0;

    frange(i, n) {
        while(dq.size() >= 2 && dq[0].eval(dist[i]) < dq[1].eval(dist[i])) dq.pop_front();
        lli v = dq[0].eval(dist[i]);
        ans = max(ans, v + (dist[n] - dist[i]) * pref[i]);
        line curr = {pref[i], -dist[i] * pref[i]};

        while(dq.size() >= 2 && curr.intersect(dq[dq.size()-2]) <= dq[dq.size()-1].intersect(dq[dq.size()-2]))
            dq.pop_back();
        dq.pb(curr);
    }

    printf("%lld", val[n-1] - ans);




}