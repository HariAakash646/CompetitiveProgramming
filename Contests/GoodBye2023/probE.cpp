#include <bits/stdc++.h>

using namespace std;

// struct chash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

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



int n;
vi vec;
vvi graph;
lli ma = 1;
lli mv = 1;
// const MAN = 1e5+5;

vector<seti> dfs(int x, int p, int d) {
    vector<seti> out;
    lli m1 = 1;
    lli m2 = 1;
    // printf("%d\n", x);
    for(auto e : graph[x]) {
        if(e != p) {
            auto v = dfs(e, x, d+1);
            lli mx = 1;
            for(auto v2 : v) {
                v2.insert(vec[x]);
                mx = max(mx, (lli)v2.size());
                out.pb(v2);
            }
            if(mx >= m1) {
                m2 = m1;
                m1 = mx;
            }
            else if(mx > m2) m2 = mx;
        }
    }
    mv = max(mv, m1);
    // printf("%lld %lld\n", m1, m2);
    ma = max(ma, m1*m2);
    if(!out.size()) {
        seti st;
        st.insert(vec[x]);
        out.pb(st);
    }
    vector<seti> out2;
    for(auto v : out) {
        if(v.size() + d > mv) out2.pb(v); 
    }
    return out2;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        scd(n);
        graph = vvi(n+1);
        vec =vi(n+1);
        ma = 1;
        mv = 1;
        forr(i, 2, n+1) {
            int p;
            scd(p);
            graph[p].pb(i);
            graph[i].pb(p);
        }

        forr(i, 1, n+1) scd(vec[i]);
        dfs(1, 0, 0);
        printf("%lld\n", ma);
    }
}