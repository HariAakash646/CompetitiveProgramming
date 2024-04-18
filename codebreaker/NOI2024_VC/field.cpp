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
    int n, t, qu;
    scd(n);
    scd(t);
    scd(qu);
    vvi grid(803, vi(803));

    frange(i, n) {
        int a, b, c, d;
        scd(a);
        scd(b);
        scd(c);
        scd(d);
        a+=401;
        b+=401;
        c+=401;
        d+=401;
        forr(i, a, b+1) forr(j, c, d+1) grid[i][j] = 1;
    }

    vvi dist(803, vi(803, 2e9));

    queue<pair<pii, int>> q;
    q.push(mp(mp(401, 401), 0));
    vector<vb> vis(803, vb(803));
    vi cnt(401);

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(p.f.f < 0 || p.f.f > 802 || p.f.s < 0 || p.f.s > 802) continue;
        if(grid[p.f.f][p.f.s] || vis[p.f.f][p.f.s]) continue;
        vis[p.f.f][p.f.s] = true;
        dist[p.f.f][p.f.s] = p.s;
        if(p.s <= 400) cnt[p.s]++;
        q.push(mp(mp(p.f.f+1, p.f.s), p.s+1));
        q.push(mp(mp(p.f.f-1, p.f.s), p.s+1));
        q.push(mp(mp(p.f.f, p.f.s+1), p.s+1));
        q.push(mp(mp(p.f.f, p.f.s-1), p.s+1));
    }
    forr(i, 1, 401) cnt[i] += cnt[i-1];

    frange(_, qu) {
        if(t == 1) {
            int x, y;
            scd(x);
            scd(y);
            x+=401;
            y+=401;
            if(!vis[x][y]) printf("-1\n");
            else
            printf("%d\n", dist[x][y]);
        }
        else {
            int m;
            scd(m);
            printf("%d\n", cnt[m]);
        }
    }
    

}