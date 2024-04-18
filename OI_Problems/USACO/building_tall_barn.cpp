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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("tallbarn.in", "r", stdin);
    freopen("tallbarn.out", "w", stdout);
}

int main() {
    usaco();
    int n;
    lli k;
    scd(n);
    sclld(k);
    vll vec(n);
    lli tot = 0;
    frange(i, n) {
        sclld(vec[i]);
        tot += vec[i];
    }
    ld v = ld(tot) / ld(k);
    ld out = 0;
    vector<pair<ld, lli>> val(n);
    priority_queue<pair<ld, int>> pq;
    frange(i, n) {
        lli x = lli(vec[i] / v);
        // printf("%lld\n", x);
        k -= x;
        val[i].s = x;
        if(x == 0) val[i].f = 1e18;
        else val[i].f = ld(vec[i]) / ld(x);
        out += val[i].f;
        pq.push(mp(val[i].f - (ld(vec[i])/ld(x+1)), i));
    }

    while(k) {
        auto p = pq.top();
        pq.pop();
        out -= p.f;
        val[p.s].s++;
        val[p.s].f = ld(vec[p.s]) / ld(val[p.s].s);
        k--;
        pq.push(mp(val[p.s].f - (ld(vec[p.s])/ld(val[p.s].s+1)), p.s));
    }

    printf("%lld", lli(round(out)));

}