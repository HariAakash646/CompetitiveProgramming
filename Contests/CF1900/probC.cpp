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

int n;
string str;
vii graph;
vi dp;

void dfs(int i) {
    if(graph[i].f == 0 && graph[i].s == 0) {
        dp[i] = 0;
        return;
    }
    if(graph[i].f) {
        dfs(graph[i].f);
        int v = 0;
        if(str[i-1] != 'L') v = 1;
        dp[i] = min(dp[i], dp[graph[i].f] + v);
    }
    if(graph[i].s) {
        dfs(graph[i].s);
        int v = 0;
        if(str[i-1] != 'R') v = 1;
        dp[i] = min(dp[i], dp[graph[i].s] + v);
    }
}

int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;

    frange(_, t) {
        
        cin >> n >> str;

        graph = vii(n+1);
        dp = vi(n+1, 1e9);

        forr(i, 1, n+1) {
            cin >> graph[i].f >> graph[i].s;
        }

        dfs(1);
        cout << dp[1] << "\n";
    }
}