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
    fastio();
    // usaco();
    int l, q;
    cin >> l >> q;
    frange(i, q) {
        char c;
        cin >> c;
        char v = c;
        int a;
        frange(i,  7) cin >> v;
        cin >> a;
        // printf("%d\n", a);

        if(c == 'a') {
            vi out;
            int v = 1<<20;
            for(int i=19; i>=0; i--) {
                if(a & (1<<i)) {
                    v += (1<<i);
                    out.pb(v);
                }
            }
            printf("%d ", (int)out.size());
            for(auto e : out) printf("%d ", e);
            printf("\n");
        }
        else if(c == 'b') {
            vi out;
            int v = 1<<20;
            for(int i=19; i>=0; i--) {
                if((a & (1<<i)) == 0) {
                    out.pb(v + (1<<i));
                }
                else v += (1<<i);
            }
            printf("%d ", (int)out.size());
            for(auto e : out) printf("%d ", e);
            printf("\n");
        }
        else {
            int b = 0;
            int c = 0;
            vi vec(a);
            frange(j, a) cin >> vec[j];
            // for(auto e : vec) printf("%d ", e);
            bool out = false;
            for(int e : vec) {
                if(e == 2) out=true;
            }
            // printf("%d %d\n", b, c);
            if(out) printf("A\n");
            else printf("B\n");
        }
    }
}