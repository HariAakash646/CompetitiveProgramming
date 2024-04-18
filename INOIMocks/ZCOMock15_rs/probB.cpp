#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    // usaco();
    int r, c;
    cin >> r >> c;

    vector<vb> tree(r, vb(c));
    queue<pair<int, pii>> q, q2;

    frange(i, r) {
        string row;
        cin >> row;

        frange(j, c) {
            if(row[j] == 'F') q.push(mp(0, mp(i, j)));
            if(row[j] == 'B') q2.push(mp(0, mp(i, j)));
            if(row[j] == '@') tree[i][j] = true;
        }
    }

    vector<vb> vis(r, vb(c));
    vvi dist(r, vi(c, 1e9));

    while(q.size()) {
        auto p = q.front().s;
        int x = q.front().f;
        q.pop();
        if(p.f < 0 || p.f >= r || p.s < 0 || p.s >= c) continue;
        if(vis[p.f][p.s]) continue;
        vis[p.f][p.s] = true;
        dist[p.f][p.s] = x;

        q.push(mp(x+1, mp(p.f+1, p.s)));
        q.push(mp(x+1, mp(p.f-1, p.s)));
        q.push(mp(x+1, mp(p.f, p.s+1)));
        q.push(mp(x+1, mp(p.f, p.s-1)));
    }

    vis = vector<vb>(r, vb(c));
    q = q2;

    while(q.size()) {
        auto p = q.front().s;
        int x = q.front().f;
        q.pop();
        if(p.f < 0 || p.f >= r || p.s < 0 || p.s >= c) {
            cout << x;
            return 0;
        }
        if(x + 1 >= dist[p.f][p.s] || tree[p.f][p.s]) continue;
        if(vis[p.f][p.s]) continue;
        vis[p.f][p.s] = true;

        q.push(mp(x+2, mp(p.f+1, p.s)));
        q.push(mp(x+2, mp(p.f-1, p.s)));
        q.push(mp(x+2, mp(p.f, p.s+1)));
        q.push(mp(x+2, mp(p.f, p.s-1)));
    }

    cout << "-1";
}