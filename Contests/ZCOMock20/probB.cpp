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

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    seti st;
    frange(i, m) {
        int a;
        scd(a);
        st.insert(a);
    }
    int k;
    scd(k);
    vvi val(k);
    vvi graph(n+1);
    vi indeg(k);

    frange(i, k) {
        int l, r;
        scd(l);
        scd(r);

        frange(j, l) {
            int a;
            scd(a);
            if(st.find(a) == st.end()) {
                graph[a].pb(i);
                indeg[i]++;
            }
        }

        frange(j, r) {
            int a;
            scd(a);
            val[i].pb(a);
        }
    }

    queue<int> q;
    frange(i, k) {
        if(!indeg[i]) q.push(i);
    }

    while(q.size()) {
        auto e = q.front();
        q.pop();
        for(auto x : val[e]) {
            if(st.find(x) == st.end()) {
                st.insert(x);
                for(auto p : graph[x]) {
                    indeg[p]--;
                    if(!indeg[p]) q.push(p);
                }
            }
        }
    }
    printf("%d\n", (int)st.size());
    for(auto e : st) printf("%d ", e);
}