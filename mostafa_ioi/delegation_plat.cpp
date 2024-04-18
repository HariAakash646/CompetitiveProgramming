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

vvi graph;

bool conf(vi &vec, int rem, int v) {
    int l = 0;
    int r = vec.size()-1;
    while(l < r) {
        if(l == rem) l++;
        if(r == rem) r--;
        if(vec[l++] + vec[r--] < v) return false;
    }
    return true;
}

int dfs(int x, int p, int v) {
    vi st;
    for(auto e : graph[x]) {
        if(e != p) {
            st.pb(dfs(e, x, v)+1);
            if(st.back() < 0) return -1e9;
        }
    }
    if(x == 1) {
        if(st.size() % 2) st.pb(0);
        sort(all(st));
        if(conf(st, -1, v)) return 0;
    }

    if(st.size() % 2 == 0) st.pb(0);
    sort(all(st));
    int lo = -1;
    int hi = st.size()-1;

    while(lo < hi) {
        int mid = (hi+lo+1)/2;
        if(conf(st, mid, v)) lo = mid;
        else hi = mid-1;
    }
    if(lo == -1) return -1e9;
    return st[lo];
}

bool check(int x) {
    int v = dfs(1, 0, x);
    // printf("%d %d\n", x, v);
    return (v==0);
}

int main() {
    // usaco();
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    int n;
    scd(n);
    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int lo = 1;
    int hi = n-1;

    while(lo!= hi) {
        int mid = (lo+hi+1)/2;
        // printf("%d\n", mid);
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    printf("%d", lo);
}