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

int h, w;
vvi grid;
vector<vb> vis, vis2;

int mi = 1e9+1;
int ma = 0;

pii mip, mapi;

void dfs(int x, int y, int v) {
    if(x < 0 || x >= h || y < 0 || y >= w) return;
    if(grid[x][y] > v) return;
    if(vis[x][y]) return;
    vis[x][y] = true;
    dfs(x+1, y, v);
    dfs(x, y+1, v);
    dfs(x-1, y, v);
    dfs(x, y-1, v);
}

void dfs2(int x, int y, int v) {
    if(x < 0 || x >= h || y < 0 || y >= w) return;
    if(grid[x][y] < v) return;
    if(vis2[x][y]) return;
    vis2[x][y] = true;
    dfs2(x+1, y, v);
    dfs2(x, y+1, v);
    dfs2(x-1, y, v);
    dfs2(x, y-1, v);
}

bool check(int x) {
    vis = vis2 = vector<vb>(h, vb(w));
    dfs(mip.f, mip.s, mi+x);
    dfs2(mapi.f, mapi.s, ma-x);

    frange(i, h) {
        frange(j, w) {
            if(!vis[i][j] && !vis2[i][j]) return false;
        }
    }
    return true;
}

int main() {
    usaco();
    scd(h);
    scd(w);

    grid = vvi(h, vi(w));
    frange(i, h) {
        frange(j, w) {
            scd(grid[i][j]);
            if(grid[i][j] < mi) {
                mi = grid[i][j];
                mip = mp(i, j);
            }
            if(grid[i][j] > ma) {
                ma = grid[i][j];
                mapi = mp(i, j);
            }
        }
    }

    int lo = 0;
    int hi = 1e9;

    while(lo != hi) {
        int mid = (lo + hi)/2;
        if(check(mid)) {
            hi = mid;
        }
        else lo = mid+1;
    }
    printf("%d", lo);

}