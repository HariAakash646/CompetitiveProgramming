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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vector<ordered_set> vec;

pair<int, lli> dfs() {
    int x;
    scd(x);
    if(x) {
        vec[x].insert(x);
        return mp(x, 0LL);
    }
    auto v1 = dfs();
    auto v2 = dfs();
    lli tot = v1.s + v2.s;
    if(vec[v1.f].size() > vec[v2.f].size()) {
        lli x1 = 0, x2 = 0;
        for(auto e : vec[v2.f]) {
            lli v = vec[v1.f].order_of_key(e);
            x1 += vec[v1.f].size() - v;
            x2 += v;
        }
        for(auto e : vec[v2.f]) vec[v1.f].insert(e);
        tot += min(x1, x2);
        return mp(v1.f, tot);
    }
    else {
        lli x1 = 0, x2 = 0;
        for(auto e : vec[v1.f]) {
            lli v = vec[v2.f].order_of_key(e);
            x1 += vec[v2.f].size() - v;
            x2 += v;
        }
        for(auto e : vec[v1.f]) vec[v2.f].insert(e);
        tot += min(x1, x2);
        return mp(v2.f, tot);
    }
}

int main() {
    // usaco();
    int n;
    scd(n);
    vec = vector<ordered_set>(n+1);

    printf("%lld", dfs().s);
}