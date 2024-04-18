// Boring implementation

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

pair<int, vvi> rec(vvi grid) {
    int n = grid.size();
    if(n == 1) return 0;

    vvi g1(n/2, vi(n/2)), g2(n/2, vi(n/2)), g3(n/2, vi(n/2)), g4(n/2, vi(n/2));
    // pii p1 = mp(0, 0);
    // pii p2 = mp(0, 0);
    // pii p3 = mp(0, 0);
    // pii p4 = mp(0, 0);
    pii pv[4] = mp(0, 0);
    frange(i, n/2) {
        frange(j, n/2) {
            g1[i][j] = grid[i][j];
            if(g1[i][j]) pv[0].f++;
            else pv[0].s++;
            g2[i][j] = grid[i+n/2][j];
            if(g2[i][j]) pv[1].f++;
            else pv[1].s++;
            g3[i][j] = grid[i][j+n/2];
            if(g3[i][j]) pv[2].f++;
            else pv[2].s++;
            g4[i][j] = grid[i+n/2][j+n/2];
            if(g4[i][j]) pv[3].f++;
            else pv[3].s++;
        }
    }
    pair<int, vvi> arr[4];
    arr[0] = rec(g1);
    arr[1] = rec(g2);
    arr[2] = rec(g3);
    arr[3] = rec(g4);
    pii out;
    int mi = 1e9;
    frange(i, 4) {
        forr(j, i+1, 4) {
            int v = 0;
            v += min(pv[i].f + pv[j].s, pv[i].s + pv[j].f);
            frange(k, 4) {
                if(k != i && k != j) v += arr[k].f;
            }
            if(v <mi){
                mi = v;
                out = mp(i, j);
            }
        }
    }
    vvi out(n, vi(n));

    return mi;
}

int main() {
    int n;
    scd(n);
    vvi grid(n, vi(n));
    frange(i, n) {

    }
}