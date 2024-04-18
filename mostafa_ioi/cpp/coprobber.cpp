#include "coprobber.h"
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

vvi graph;
int n;
bool vis[510][510][2];
int win[510][510][2];
int nex[510][510][2];

int pos = -1;

int start(int N, bool A[MAX_N][MAX_N])
{
    n = N;
    graph = vvi(n);

    frange(i, n) {
        frange(j, n) {
            if(A[i][j]) graph[i].pb(j);
            vis[i][j][0] = vis[i][j][1] = false;
            nex[i][j][0] = nex[i][j][1] = -1;
        }
    }

    frange(i, n) {
        frange(j, n) {
            win[i][j][1] = 1;
            win[i][j][0] = graph[j].size();
        }
    }

    queue<pair<pii, int>> q;
    frange(i, n) {
        win[i][i][0] = win[i][i][1] = 0;
        q.push(mp(mp(i, i), 1));
        q.push(mp(mp(i, i), 0));
    }

    while(q.size()) {
        auto p = q.front();
        q.pop();
        int c = p.f.f;
        int r = p.f.s;
        int t = p.s;
        if(vis[c][r][t]) continue;

        if(t) {
            for(auto e : graph[r]) {
                win[c][e][0]--;
                if(!win[c][e][0]) q.push(mp(mp(c, e), 0));
            }
        }
        else {
            graph[c].pb(c);
            for(auto e : graph[c]) {
                if(win[e][r][1]) {
                    win[e][r][1] = 0;
                    nex[e][r][1] = c;
                    q.push(mp(mp(e, r), 1));
                }
            }
            graph[c].pop_back();
        }

    }
    bool w = false;
    int nx = -1;
    frange(i, n) {
        bool curr = true;
        frange(j, n) {
            if(win[i][j][1]) curr = false;
        }
        if(curr) {
            w = true;
            nx = i;
        }
    }
    pos = nx;
    return nx;
}

int nextMove(int R)
{
    pos = nex[pos][R][1];
    return pos;
}
