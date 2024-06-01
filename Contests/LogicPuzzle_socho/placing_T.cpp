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

int c = 0;
int beg;
int n;
vvi grid;
vb reg;
vector<seti> act;

vi out;

int process(int r) {
    // printf("%d ", r);
    if(act[r].empty()) {return -1;}
    if(r == n-1) {
        int c = *act[r].begin();
        // printf("\n");
        if(!reg[grid[r][c]])
            {out.pb(c);return *act[r].begin();}
        else return -1;
        
    }
    c++;

    if(c >= 5e4) return -2;

    for(auto c : act[r]) {
        if(!reg[grid[r][c]]) {
            vii add;
            forr(j, r+1, n) if(act[j].count(c)) {act[j].erase(c);add.pb(mp(j, c));}
            if(r+1 < n && act[r+1].count(c+1)) {act[r+1].erase(c+1); add.pb(mp(r+1, c+1));}
            if(r + 1 < n && act[r+1].count(c-1)) {act[r+1].erase(c-1); add.pb(mp(r+1, c-1));}
            reg[grid[r][c]] = true;
            int v = process(r+1);
            reg[grid[r][c]] = false;
            for(auto p : add) act[p.f].insert(p.s);
            if(v==-2) return -2;
            if(v != -1) {
                out.pb(c);
                return c;
            }
            
        }
    }
    // printf("\n");
    return -1;


}

int main() {
    usaco();
    // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    fastio();
    int t;
    t = 1;

    frange(_, t) {
        cin >> n;
        grid = vvi(n, vi(n));

        frange(i, n) {
            int x;
            cin >> x;
            frange(j, x) {
                int r, c;
                cin >> r >> c;
                r--;
                c--;
                grid[r][c] = i;
            }
        }
        // frange(i, n) {
        //     frange(j, n) {
        //         printf("%d ", grid[i][j]);
        //     }
        //     printf("\n");
        // }
        // return 0;
        if(n >= 374) {
            frange(i, n) {
                frange(j, n) {
                    cout << '?';
                }
                cout << "\n";
            }
            return 0;
        }

        act=vector<seti>(n);
        frange(i, n) {
            frange(j, n) act[i].insert(j);
        }

        reg = vb(n);

        int v = process(0);
        if(v <= -1) {
            frange(i, n) {
                frange(j, n) {
                    cout << '?';
                }
                cout << "\n";
            }
            return 0;
        }

        vector<string> outs(n);
        frange(i, n) {
            frange(j, n) outs[i] += '-';
        }
        reverse(all(out));
        // for(auto e : out) cout << e << "\n";
        frange(i, n) outs[i][out[i]] = 'T';

        for(auto e : outs) cout << e << "\n";

        // cout << int(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()) << "\n";

    }
}