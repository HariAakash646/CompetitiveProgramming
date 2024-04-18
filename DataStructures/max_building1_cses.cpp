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

int main() {
    // usaco();
    fastio();

    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    frange(i, n) {
        string row;
        cin >> row;
        frange(j, m) {
            if(row[j] == '*') grid[i][j] = 1;
        }
    }
    vi cnt(m);
    frange(i, m) {
        bool done = false;
        frange(j, n) {
            if(grid[j][i] == 1) {
                cnt[i] = j;
                done = true;
                break;
            }
        }
        if(!done) cnt[i] = n;
    }

    int ma = 0;
    frange(i, n) {
        // frange(i, m) printf("%d ", cnt[i]);
        // printf("\n");
        stack<pii> stk;
        frange(i, m) {
            while(stk.size() && stk.top().f >= cnt[i]) {
                pii p = stk.top();
                stk.pop();
                int l = 0;
                if(stk.size()) {
                    l = stk.top().s + 1;
                }
                ma = max(ma, p.f * (i - l));
            }
            if(stk.size()) {
                ma = max(ma, cnt[i] * (i - stk.top().s));
            }
            else ma = max(ma, cnt[i] * (i+1));
            stk.push(mp(cnt[i], i));
        }
        while(stk.size()) {
            pii p = stk.top();
            stk.pop();
            if(stk.size()) {
                pii p2 = stk.top();
                ma = max(ma, p.f * (m - p2.s-1));
                // printf("%d\n", p.f * (m - p2.s-1));
            }
            else ma = max(ma, p.f * (m));

        }
        frange(j, m) {
            if(grid[i][j] == 1) {
                bool done = false;
                forr(k, i+1, n) {
                    if(grid[k][j] == 1) {
                        cnt[j] = k - i - 1;
                        done = true;
                        break;
                    }
                }
                if(!done) cnt[j] = n - i - 1;
            }
            else {
                cnt[j]--;
            }
        }
    }
    cout << ma;
}