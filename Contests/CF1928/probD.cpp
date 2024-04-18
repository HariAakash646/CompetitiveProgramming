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

int n;
lli b, x;

vll vec;
vector<vll> val;

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        scd(n);
        sclld(b);
        sclld(x);
        vec = vll(n);
        lli m1 = 0;
        frange(i, n) {
            sclld(vec[i]);
            m1 = max(m1, vec[i]);
        }

        val = vector<vll>(n);

        frange(i, n) {
            lli v = vec[i];
            val[i].pb(0);

            forr(c, 1, vec[i]+1) {
                lli ct = c;
                lli e = v;
                lli tot = 0;
                while(e > 0) {
                    lli v1 = (e + ct - 1) /ct;
                    tot += v1 * (e-v1) * b;
                    e -= v1;
                    ct--;
                }
                // printf("%lld %d %lld\n", c, i, tot);
                val[i].pb(tot);
            }

        }
        vll tot(m1+1);
        lli vl = 0;
        seti st;
        forr(i, 0, n) st.insert(i);
        forr(i, 1, m1+1) {
            vi er;
            for(auto e : st) {
                if(val[e].size() <= i) {
                    er.pb(e);
                    continue;
                }
                vl += val[e][i] - val[e][i-1];
            }
            for(auto e : er) st.erase(e);
            tot[i] = vl;
            // printf("%lld ", tot[i]);
        }
        lli ma = 0;
        forr(i, 1, m1+1) ma = max(ma, tot[i] - (i - 1) * x);
        printf("%lld\n", ma);
    }
}