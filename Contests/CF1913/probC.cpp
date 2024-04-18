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
    int m;
    scd(m);
    vi cnt(33);
    frange(i, m) {
        int t, v;
        scd(t);
        scd(v);
        // printf("%lld\n", 1LL<<31);
        if(t == 1) {
            cnt[v]++;
        }
        else {
            vi tmp = cnt;
            bool done = true;
            frange(i, 32) {
                if(v & (1LL<<i)) {
                    if(tmp[i] == 0) {
                        done = false;
                        break;
                    }
                    tmp[i]--;
                }
                tmp[i+1] += tmp[i]/2;
            }
            if(done) printf("YES\n");
            else printf("NO\n");
        }
    }
}