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

vi disset;
vi sze;
vi cnt;
lli curr = 0;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u == v) return;
    if(sze[v] > sze[u]) swap(u, v);
    disset[v] = u;
    cnt[sze[v]]--;
    cnt[sze[u]]--;
    sze[u] += sze[v];
    cnt[sze[u]]++;
    // printf("%lld ; ", curr);
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n+2);

    frange(i, m) {
        int u, v;
        scd(u);
        scd(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }

    lli tot = 0;
    curr = 0;

    forr(i, 1, n+1) sort(all(graph[i]));

    forr(i, 1, n+1) {
        // sort(all(graph[i]));
        int l = 0;
        int r = n+1;
        auto it = lower_bound(all(graph[i]), i);
        if(it != graph[i].end()) {
            r = *it;
        }
        if(it != graph[i].begin()) {
            it--;
            l = *it;
        }
        int l2 = 0;
        if(it != graph[i].begin()) {
            it--;
            l2 = *it;
        }
        // sort(all(graph[l]));
        auto it2 = lower_bound(all(graph[l]), l);
        int r2 = r;
        if(it2 != graph[l].end()) {
            if(*it2 < i) r2 = i;
            else {
                auto it3 = upper_bound(all(graph[l]), i);
                if(it3 != graph[l].end())
                    r2 = min(r2, *it3);
            }
        }
        if(it2 != graph[l].begin()) {
            it2--;
            l2 = max(l2, *it2);
        }
        tot += lli(i-l) * (r-i);
        // printf("%d %d %d\n", i, l, r);
        tot += max(0, (l-l2)) * lli(r2-i);
        // printf("%d %d\n", l2, r2);

        r2 = n+1;
        it = lower_bound(all(graph[i]), i);
        if(it != graph[i].end()) {
            it++;
            if(it != graph[i].end()) {
                r2 = *it;
            }
        }
        // sort(all(graph[r]));
        it2 = lower_bound(all(graph[r]), r);
        l2 = l;
        if(it2 != graph[r].begin()) {
            it2--;
            if(*it2 > i) l2 = i;
            else {
                auto it3 = lower_bound(all(graph[r]), i);
                if(it3 != graph[r].begin())
                    l2 = max(l2, *prev(it3));
            }
        }
        it2 = lower_bound(all(graph[r]), r);
        if(it2 != graph[r].end()) {
            r2 = min(r2, *it2);
        }
        tot += lli(i-l2) * max(0, (r2-r));
        // printf("%d %d\n", l2, r2);
    } 
    printf("%lld", tot);
}