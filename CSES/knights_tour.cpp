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

int timer = 1;
int out[8][8] = {0};
bool vis[8][8] = {false};
vii val;


bool free(int x, int y) {
    if(x >= 0 && x < 8 && y >= 0 && y < 8 && !vis[x][y]) return true;
    else return false;
}

bool cmp(pii &x, pii &y) {
    int c1 = 0;
    int c2 = 0;

    for(auto p : val) {
        if(free(x.f+p.f, x.s+p.s)) c1++;
        if(free(y.f+p.f, y.s+p.s)) c2++;
    }
    return c1 < c2;

}

bool dfs(int x, int y, int d) {
    vis[x][y] = true;

    if(d == 64) return true;

    vii pos;

    for(auto p : val) {
        if(free(x+p.f, y+p.s)) pos.pb(mp(x+p.f, y+p.s));
    }
    sort(all(pos), cmp);

    for(auto p : pos) {
        bool ou = dfs(p.f, p.s, d+1);
        if(ou) {
            out[p.f][p.s] = d+1;
            return true;
        }
    } 

    vis[x][y] = false;
    return false;
}

int main() {
    int x, y;
    scd(x);
    scd(y);
    x--;
    y--;
    
    out[y][x] = 1;

    val.pb(mp(2, 1));
    val.pb(mp(2, -1));
    val.pb(mp(-2, 1));
    val.pb(mp(-2, -1));
    val.pb(mp(1, 2));
    val.pb(mp(1, -2));
    val.pb(mp(-1, 2));
    val.pb(mp(-1, -2));

    dfs(y, x, 1);

    frange(i, 8) {
        frange(j, 8) printf("%d ", out[i][j]);
        printf("\n");
    }
}