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
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        vvi grid(n, vi(m));
        frange(i, n) {
            frange(j, m) scd(grid[i][j]);
        }

        vvi hgt(n, vi(m));
        frange(j, m) {
            hgt[n-1][j] = 1;
            for(int i=n-2; i>=0; i--) {
                hgt[i][j] = 1;
                if(grid[i][j] == grid[i+1][j]) hgt[i][j] += hgt[i+1][j];
            }
        }
        lli tot = 0;
        frange(i, n) {
            tot += hgt[i][0];
            stack<pair<pii, lli>> stk;
            stk.push(mp(mp(0, -1), 0));
            stk.push(mp(mp(hgt[i][0], 0), hgt[i][0]));
            forr(j, 1, m) {
                if(grid[i][j] != grid[i][j-1]) {
                    stk = {};
                    stk.push(mp(mp(0, j-1), 0));
                }
                while(stk.size() && stk.top().f.f >= hgt[i][j]) stk.pop();
                tot += (lli)hgt[i][j] * (j-stk.top().f.s);
                tot += stk.top().s;
                stk.push(mp(mp(hgt[i][j], j), (lli)hgt[i][j] * (j-stk.top().f.s) + stk.top().s));
            }
        }
        printf("%lld\n", tot);
    }
}