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
    scd(n); scd(m);
    map<int, int> mv, mvy;
    int py = -1;

    int my = 1e9+1;

    frange(i, n) {
        int x, y;
        scd(x);
        scd(y);
        
        
        my = min(my, y);
    }

    for(auto p : vec) {
        int x = p.f;
        int y = p.s-y;
        mv[x] = max(mv[x], y);
        mvy[y] = max(x, mvy[y]);
    }
    int out = 0;
    for(auto p : mv) {
        // printf("%d %d\n", p.f, p.s);
        if(p.s%2) break;
        if(p.f%2 && mvy[p.s] == p.f) {
            out = p.f-1;
            break;
        }
        out = p.f;
    }
    printf("%d", out);
}