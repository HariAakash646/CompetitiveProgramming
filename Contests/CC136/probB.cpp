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

int v;

bool cmp(int x, int y) {
    return (x & v) > (y & v);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);

        vvi act(1);
        for(auto e : vec) act[0].pb(e);

        for(int i=30; i>=0; i--) {
            bool done = true;
            vvi act2;
            for(auto v : act) {
                if(done) {
                    vi v1, v2;
                    for(auto e : v) {
                        if(e & (1<<i)) v1.pb(e);
                        else v2.pb(e);
                    }
                    act2.pb(v1);
                    if(v2.size()) {
                        done = false;
                        act2.pb(v2);
                    }
                }
                else act2.pb(v);
            }
            act = act2;
        }
        vi out(n);
        int id = 0;
        for(auto v : act) {
            for(auto e: v)
                out[id++] = e;
        }
        forr(i, 1, n) out[i] = out[i] & out[i-1];
        for(auto e : out) printf("%d ", e);
        printf("\n");
    }
}