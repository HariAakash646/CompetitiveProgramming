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

int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;
    frange(_, t) {
        int n;
        cin >> n;

        vector<string> grid(2);
        cin >> grid[0] >> grid[1];

        queue<pii> q;
        q.push(mp(0, 0));

        bool done = false;

        vector<vb> vis(2, vb(n));

        while(q.size()) {
            auto p = q.front();
            q.pop();
            if(p.f > 1 || p.f < 0 || p.s < 0 || p.s >= n || vis[p.f][p.s]) continue;
            if(p.f == 1 && p.s == n-1) {
                done = true;
                break;
            }
            vis[p.f][p.s] = true;
            if(p.f+1 <= 1) {
                pii p2 = mp(p.f+1, p.s);
                if(grid[p2.f][p2.s] == '<') p2.s--;
                else p2.s++;
                q.push(p2);
            }
            if(p.f - 1>=0) {
                pii p2 = mp(p.f-1, p.s);
                if(grid[p2.f][p2.s] == '<') p2.s--;
                else p2.s++;
                q.push(p2);
            }
            if(p.s + 1 < n) {
                pii p2 = mp(p.f, p.s+1);
                if(grid[p2.f][p2.s] == '<') p2.s--;
                else p2.s++;
                q.push(p2);
            }
            if(p.s -1 >=0) {
                pii p2 = mp(p.f, p.s-1);
                if(grid[p2.f][p2.s] == '<') p2.s--;
                else p2.s++;
                q.push(p2);
            }
        }
        if(done) cout << ("YES\n");
        else cout << ("NO\n");
    }
}