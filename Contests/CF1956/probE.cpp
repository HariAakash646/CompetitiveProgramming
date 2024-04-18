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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vi vec(n);
        vi act;
        seti out;
        frange(i, n) {scd(vec[i]); act.pb(i);}

        vb atb(n+1, true);

        while(act.size()) {
            // seti er;
            for(auto e : act) {
                if(vec[e] == 0) {
                    atb[e] = false;
                    if(vec[(e+1)%n]) out.insert((e+1)%n);
                    continue;
                }
                vec[(e+1)%n] = max(0, vec[(e+1)%n] - vec[e]);
                if(vec[(e+1)%n] == 0) atb[e] = false;
                else if(vec[(e+2)%n] == 0 && vec[(e-1+n)%n] == 0) {
                    out.insert(e);
                    atb[e] = false;
                    atb[(e+1%n)] = false;
                }
            }
            vi nex;
            for(auto e : act) {
                if(atb[e]) nex.pb(e);
            }
            act = nex;
        }
        // sort(all(out));

        printf("%d\n", (int)out.size());
        for(auto e : out) printf("%d ", e+1);
        printf("\n");
    }
}