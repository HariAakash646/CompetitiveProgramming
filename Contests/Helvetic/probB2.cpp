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
    int n;
    scd(n);
    vii vec(n);

    frange(i, n) {
        scd(vec[i].f);
        vec[i].s = i+1;
    }
    sort(all(vec), greater<>());

    int curr = 1;
    vii out(n+1);
    out[vec[0].s] = mp(1, 1);
    vi val(n+1);
    bool ad = true;
    int en = n;
    forr(i, 1, n) {
        if(vec[i-1].f == 0) {
            en = i;
            break;
        }
        if(ad) curr += (vec[i-1].f-1);
        else curr -= (vec[i-1].f-1);
        out[vec[i].s] = mp(i+1, curr);
        ad = !ad;
        val[vec[i-1].s] = vec[i].s; 
    }
    forr(i, en, n) out[vec[i].s] = mp(i+1, 1);
    forr(i, en-1, n)
        val[vec[i].s] = vec[i].s;
    printf("YES\n");
    forr(i, 1, n+1) {
        auto p = out[i];
        printf("%d %d\n", p.f, p.s);
    }
    forr(i, 1, n+1) printf("%d ", val[i]);

}