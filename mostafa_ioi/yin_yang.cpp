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

lli tot = 0;

vb vis;
vi sze;
vector<vii> graph;

int get_size(int x, int p=-1) {
    sze[x] = 1;
    for(auto e : graph[x]) {
        if(e.f != p && !vis[e.f]) {
            sze[x] += get_size(e.f, x);
        }
    }
    return sze[x];
}

int get_centroid(int x, int subsz, vi &vec, int p=-1) {
    for(auto e : graph[x]) {
        if(e.f != p && !vis[e.f] && 2*sze[e.f] > subsz) {
            auto out = get_centroid(e.f, subsz, vec, x);
            vec.pb(e.s);
            return out;
        }
    }
    return x;
}

pair<mpii, mpii> decomp(int x) {
    int sz = get_size(x);
    vi vec;
    x = get_centroid(x, sz, vec);
    vis[x] = true;

    pair<mpii, mpii> st;
    st.f[0]++;

    for(auto e : graph[x]) {
        if(!vis[e.f]) {
            pair<mpii, mpii> val = decomp(e.f);
            for(auto p : val.f) {
                int v = p.f + e.s;
                tot += p.s * st.s[-v];
            }
            for(auto p : val.s) {
                int v = p.f + e.s;
                tot += p.s * (st.f[-v] + st.s[-v]);
            }
            for(auto p : val.f) {
                int v = p.f + e.s;
                if(v == 0) st.s[v]++;
                else st.f[v]++;
            }
            for(auto p : val.s) {
                int v = p.s + e.s;
                st.s[v]++;
            }
        }
    }
    seti st1;
    int v=0;
    
    forr(i, 1, vec.size()) {
        vec[i] += vec[i-1];
        if(i != vec.size()-1)
            st1.insert(vec[i]);
    }

    if(vec.size()) {v = vec.back(); st1.insert(vec[0]);}

    pair<mpii, mpii> out;
    printf("%d %lld\n", x, tot);
    for(auto p : st.f) {
        // printf("%d\n", p.f+v);
        if(st1.find(-p.f) != st1.end()) {
            out.s[p.f + v]+=p.s;
        }
        else out.f[p.f+v]+=p.s;
    }
    for(auto p :st.s) {
        // printf("%d\n", p.f+v);
        out.s[p.f+v] += p.s;
    }
    for(auto p : out.f) printf("v1: %d %d\n", p.f, p.s);
    for(auto p : out.s) printf("v2: %d %d\n", p.f, p.s);
    return out;
}

int main() {
    usaco();
    // freopen("yinyang.in", "r", stdin);
    // freopen("yinyang.out", "w", stdout);
    int n;
    scd(n);

    graph = vector<vii>(n+1);

    frange(i, n-1) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        if(c == 0) c = -1;
        graph[a].pb(mp(b, c));
        graph[b].pb(mp(a, c));
    }

    vis = vb(n+1);
    sze = vi(n+1);

    decomp(1);

    printf("%lld", tot);
}