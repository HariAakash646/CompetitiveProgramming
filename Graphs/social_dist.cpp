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

vector<vii> graph;
int n, m;
vi val;

bool dfs(int x, lli v, int c) {
    if(val[x] != -1) {
        return val[x] == c;
    }

    mseti st;

    val[x] = c;

    for(auto p : graph[x]) {
        if(p.s < v) {
            bool out = dfs(p.f, v, !c);
            st.insert(p.s);
            if(!out) return false;
        }
    }

    if(st.size() >= 2) {
        if(*st.begin() + *next(st.begin()) < v) return false;
    }
    return true;
}

bool check(lli v) {
    forr(i, 1, n+1) {
        if(val[i] == -1) {
            bool out = dfs(i, v, 0);
            if(!out) return false;
        }
    }
    return true;
}

int main() {
    // usaco();
    scd(n);
    scd(m);

    graph = vector<vii>(n+1);

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }

    lli lo = 0;
    lli hi = 1e15;

    while(lo != hi) {
        lli mid = (lo+hi+1)/2;
        val = vi(n+1, -1);
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }

    printf("%lld", lo);
}