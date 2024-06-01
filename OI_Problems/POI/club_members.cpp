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

    vi vec(m);
    frange(i, m) scd(vec[i]);

    vvi pos0(n), pos1(n);

    frange(i, n) {
        frange(j, m) {
            if(vec[j] & (1<<i)) pos0[i].pb(j);
            else pos1[i].pb(j);
        }
    }
    lli tot = 0;
    frange(j, m) {
        pii p = mp(1, m-1);
        frange(i, n) {
            if(pos0[i].size()) {
                auto it = lower_bound(all(pos0[i]), j);
                if(it != pos0[i].end()) {
                    p.f = max(p.f, *it-j);
                }
                else {
                    p.f = max(p.f, m-j+*pos0[i].begin());
                }
                if(it != pos0[i].begin()) {
                    it--;
                    p.s = min(p.s, m-j+(*it-1));
                }
                else {
                    if(pos0[i].size() == 1) {
                        p.s = 0;
                        break;
                    }
                    p.s = min(p.s, (pos0[i].back()-1)-j);
                }
            }
            if(pos1[i].size()) {
                auto it = lower_bound(all(pos1[i]), j);
                if(it != pos1[i].end()) {
                    p.f = max(p.f, *it-j);
                }
                else {
                    p.f = max(p.f, m-j+*pos1[i].begin());
                }
                if(it != pos1[i].begin()) {
                    it--;
                    p.s = min(p.s, m-j+(*it-1));
                }
                else {
                    if(pos1[i].size() == 1) {
                        p.s = 0;
                        break;
                    }
                    p.s = min(p.s, (pos1[i].back()-1)-j);
                }
            }
        }
        // printf("%d %d %d\n", j, p.f, p.s);
        tot += max(0, p.s-p.f+1);
    }
    printf("%lld", tot/2);
}