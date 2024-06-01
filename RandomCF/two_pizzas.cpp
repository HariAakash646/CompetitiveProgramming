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
    usaco();
    int n, m;
    scd(n);
    scd(m);

    vi vec(n);

    frange(i, n) {
        int c;
        scd(c);
        frange(_, c) {
            int x;
            scd(x);
            x--;
            vec[i] = vec[i] | (1<<x);
        }
    }

    vector<pair<lli, int>> val(1<<9, mp(2e9+5, 0));
    vector<pair<lli, pii>> val2(1<<9, mp(2e9+5, mp(0, 0)));


    frange(i, m) {
        int c, r;
        scd(c);
        scd(r);
        int v = 0;
        frange(i, r) {
            int x;
            scd(x);
            x--;
            v = v | (1<<x);
        }

        frange(j, 1<<9) {
            val2[j|v] = min(val2[j|v], mp(val[j].f+c, mp(val[j].s, i+1)));
        }
        val[v] = min(val[v], mp(lli(c), i+1));
    }

    int ma = 0;
    lli mi = 2e9+5;
    pii id;
    frange(i, 1<<9) {
        int c = 0;
        if(val2[i].f>=2e9+5) continue;
        frange(j, n) {
            if((i|vec[j])==i) c++;
        }
        // printf("%d %d\n", i, c);
        if(c > ma) {
            ma = c;
            mi = val2[i].f;
            id = val2[i].s;
        }
        else if(c==ma) {
            if(val2[i].f < mi) {
                mi = val2[i].f;
                id = val2[i].s;
            }
        }
    }
    // printf("%d %lld", ma, mi);
    printf("%d %d", id.f, id.s);
}