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

int n, m;
vector<string> grid;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    // usaco();
    fastio();
    cin >> n >> m;
    grid = vector<string>(n);

    frange(i, n) cin >> grid[i];

    vector<vb> up(n, vb(m)), left(n, vb(m));
    frange(i, n) {
        frange(j, m) {
            if(grid[i][j] == 'G' && check(i-1, j) && check(i+1, j) && grid[i-1][j] == 'R' && grid[i+1][j] == 'W') up[i][j] = true;
            if(grid[i][j] == 'G' && check(i, j-1) && check(i, j+1) && grid[i][j-1] == 'R' && grid[i][j+1] == 'W') left[i][j] = true;
            // cout <<  i << " " << j << " " << check(i, j) << "\n";
        }
    }

    vvi dpu(n, vi(m)), dpl(n, vi(m));

    frange(i, n) {
        for(int j=m-1; j>=0; j--) {
            if(check(i-1, j+1)) {
                dpu[i][j] = dpl[i][j] = max(dpu[i-1][j+1], dpl[i-1][j+1]);
            }
            if(up[i][j]) {
                if(check(i-1, j+1)) dpu[i][j] = max(dpu[i][j], dpu[i-1][j+1] + 1); 
                else dpu[i][j] = 1;
            }
            if(left[i][j]) {
                if(check(i-1, j+1)) dpl[i][j] = max(dpl[i][j], dpl[i-1][j+1] + 1);
                else dpl[i][j] = 1;
            }
            
        } 
    }
    int tot = 0;
    frange(i, n) tot += max(dpu[i][0], dpl[i][0]);
    forr(i, 1, m) tot += max(dpu[n-1][i], dpl[n-1][i]);

    cout << tot;
}