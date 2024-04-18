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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


vvi grid;
int n, m, q1;



bool check(int v, int x, int y) {
    queue<pii> q;
    q.push(mp(x, y));
    vector<vb> vis(n, vb(m));

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(p.f < 0 || p.f >= n || p.s < 0 || p.s >= m) continue;
        if(vis[p.f][p.s] || grid[p.f][p.s] < v) continue;
        vis[p.f][p.s] = true;

        q.push(mp(p.f, p.s+1));
        q.push(mp(p.f, p.s-1));
        q.push(mp(p.f+1, p.s));
        q.push(mp(p.f-1, p.s));
    }

    q = {};

    frange(i, n) {
        frange(j, m) {
            if(grid[i][j] == -1) q.push(mp(i, j));
        }
    }

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(p.f < 0 || p.f >= n || p.s < 0 || p.s >= m) continue;
        if(vis[p.f][p.s]) continue;
        if(p.f == 0 || p.f == n-1 || p.s == 0 || p.s == m-1) return false;
        vis[p.f][p.s] = true;

        q.push(mp(p.f, p.s+1));
        q.push(mp(p.f, p.s-1));
        q.push(mp(p.f+1, p.s));
        q.push(mp(p.f-1, p.s));
        q.push(mp(p.f+1, p.s+1));
        q.push(mp(p.f+1, p.s-1));
        q.push(mp(p.f-1, p.s+1));
        q.push(mp(p.f+1, p.s-1));
    }
    return true;
}

int main() {
    // usaco();
    fastio();
    cin >> n >> m >> q1;
    grid = vvi(n, vi(m, 1e9));
    frange(i, n) {
        string str;
        cin >> str;
        frange(j, m) {
            if(str[j] == 'v') grid[i][j] = 0;
            else if(str[j] == '#') grid[i][j] = -1;
        }
    }

    queue<pair<int, pii>> q;
    frange(i, n) {
        frange(j, m) {
            if(grid[i][j] == 0) q.push(mp(0, mp(i, j)));
        }
    }
    vector<vb> vis(n, vb(m));
    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(p.s.f < 0 || p.s.f >= n || p.s.s < 0 || p.s.s >= m) continue;
        if(vis[p.s.f][p.s.s] || (grid[p.s.f][p.s.s] < p.f && grid[p.s.f][p.s.s] != -1)) continue;
        vis[p.s.f][p.s.s] = true;
        if(grid[p.s.f][p.s.s] != -1)
        grid[p.s.f][p.s.s] = p.f;

        q.push(mp(p.f+1, mp(p.s.f, p.s.s+1)));
        q.push(mp(p.f+1, mp(p.s.f, p.s.s-1)));
        q.push(mp(p.f+1, mp(p.s.f+1, p.s.s)));
        q.push(mp(p.f+1, mp(p.s.f-1, p.s.s)));
    }

    // frange(i, n) {
    //     frange(j, m) cout << grid[i][j] << " ";
    //     cout << "\n";
    // }


    frange(i, q1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int lo = 0;
        int hi = n+m;
    
        while(lo != hi) {
            int mid = (lo+hi+1)/2;
            if(check(mid, x, y)) lo = mid;
            else hi = mid-1;
        }
        cout << lo << "\n";
    }
}