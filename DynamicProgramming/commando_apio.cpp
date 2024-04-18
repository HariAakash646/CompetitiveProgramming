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

    lli a, b, c;
    sclld(a);
    sclld(b);
    sclld(c);

    vll vec(n);
    frange(i, n) sclld(vec[i]);

    vll pref(n);
    pref[0] = vec[0];
    forr(i, 1, n) pref[i] = pref[i-1] + vec[i];

    deque<line> dq;
    line curr = {0, 0};
    dq.pb(curr);
    lli ans = 0;
    for(auto e : pref) {
        while(dq.size() >= 2 && dq[1].eval(e) >= dq[0].eval(e)) dq.pop_front();
        lli v = dq[0].eval(e) + e*e*a + e * b + c;
        ans = max(ans, v);

        line curr = {-2 * e * a, e * e * a - e * b + v};

        while(dq.size() >= 2 && curr.intersect(dq[dq.size()-1]) <= dq[dq.size()-1].intersect(dq[dq.size()-2])) 
            dq.pop_back();
        dq.pb(curr);
    }
    printf("%lld", ans);
}