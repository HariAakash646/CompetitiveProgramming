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

lli val(lli x, int k) {
    lli v = (x+k-1) / k;
    lli tot = 0;
    lli y = x + k - v * k;
    tot = v * v * y + (v-1) * (v-1) * (k-y);
    return tot;
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    k -= n;
    vll vec(n);
    priority_queue<pair<lli, pii>> pq;
    lli tot = 0;
    frange(i, n) {
        sclld(vec[i]);
        tot += vec[i] * vec[i];
        pq.push(mp(val(vec[i], 1) - val(vec[i], 2), mp(i, 2)));
    }

    frange(i, k) {
        auto p = pq.top();
        pq.pop();
        tot -= p.f;
        int id = p.s.f;
        int x = p.s.s;
        pq.push(mp(val(vec[id], x) - val(vec[id], x+1), mp(id, x+1)));
    }
    printf("%lld\n", tot);

}