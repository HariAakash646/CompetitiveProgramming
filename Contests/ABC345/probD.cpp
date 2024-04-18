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

vii vec;
int n;
int ho, wo;

bool dfs(vi grid, int i) {
    int val = (1<<wo) - 1;
    bool out = true;
    // printf("%d: ", vis);
    // frange(i, h) printf("%d ", grid[i]);
    // printf("\n");
    int h = ho;
    int w = wo;
    if(i == 0) {
        h = (h+1)/2;
        w = (w+1)/2;
    }
    frange(j, ho) {
        if(grid[j] != val) out = false;
    }
    if(out) return true;
    if(i >= n) return false;
    int r = vec[i].f;
    int c = vec[i].s;
    
    frange(j, h-r+1) {
        frange(k, w-c+1) {
            vi tmp = grid;
            bool done = true;
            int val = 0;
            forr(x, k, k+c) val = val ^ (1<<x);
            forr(e, j, j+r) {
                if(tmp[e] & val) {
                    done = false;
                    break;
                }
                tmp[e] = tmp[e] ^ val;
            }
            if(done)
            {
                bool v = dfs(tmp, i+1);
                if(v) return true;
            }
        }
    }
    if(r != c) {
        swap(r, c);
        frange(j, h-r+1) {
            frange(k, w-c+1) {
                vi tmp = grid;
                bool done = true;
                int val = 0;
                forr(x, k, k+c) val = val ^ (1<<x);
                forr(e, j, j+r) {
                    if(tmp[e] & val) {
                        done = false;
                        break;
                    }
                    tmp[e] = tmp[e] ^ val;
                }
                if(done)
                {
                    bool v = dfs(tmp, i+1);
                    if(v) return true;
                }
            }
        }
    }
    
    return dfs(grid, i+1);
}

int main() {
    // usaco();
    scd(n);
    scd(ho);
    scd(wo);
    vec = vii(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    vi grid(ho);

    bool out = dfs(grid, 0);
    if(out) {
        printf("Yes");
    }
    else printf("No");
}