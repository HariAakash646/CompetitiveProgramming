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
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    vector<vector<pair<int, pii>>> row(n+1);
    vector<vector<pair<int, pii>>> col(m+1);

    vvi grid(n+1, vi(m+1));

    frange(i, k) {
        int r, c, t, fr;
        scd(r);
        scd(c);
        scd(t);
        scd(fr);
        row[r].pb(mp(c, mp(t, fr)));
        col[c].pb(mp(r, mp(t, fr)));
        grid[r][c] = -1;
        forr(i, 1, n+1) {
            if(i == r) continue;
            int ti = i + c - 2;
            if(ti >= t && (ti - t) - abs(i - r) >= 0 && abs((ti - t) - abs(i - r)) % fr == 0) {
                grid[i][c] = -1; 
                // printf("%d %d %d\n", i, c, ti);
            }
        }
        forr(i, 1, m+1) {
            if(i == c) continue;
            int ti = i + r - 2;
            if(ti >= t && (ti - t) - abs(i - c) >= 0 && abs((ti - t) - abs(i - c)) % fr == 0) {
                grid[r][i] = -1; 
                // printf("%d %d %d\n", r, i, ti);
            }
        }
    }

    queue<pii> q;
    q.push(mp(1, 1));
    vector<vb> vis(n+1, vb(m+1));

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(vis[p.f][p.s] || grid[p.f][p.s] == -1) continue;
        vis[p.f][p.s] = true;

        if(p.f == n && p.s == m) {
            printf("YES\n");
            printf("%d\n", p.f+p.s-2);
            return 0;
        }

        if(p.f + 1 <= n) q.push(mp(p.f+1, p.s));
        if(p.s + 1 <= m) q.push(mp(p.f, p.s+1));
    }

    printf("NO\n");
}