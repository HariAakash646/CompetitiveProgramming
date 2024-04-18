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

int trie[200005][26] = {-1};
bool player[200005][2] = {false};
int idx = 0;

void add(string str, int id) {
    int x = 0;
    frange(i, str.size()) {
        int c = str[i] - 'a';
        if(trie[x][c] != -1) {
            x = trie[x][c];
            player[x][id] = true;
        }
        else {
            trie[x][c] = ++idx;
            x = idx;
            player[x][id] = true;
        }
    }
}

bool dfs(int x, int id) {
    bool out = true;
    frange(i, 26) {
        if(trie[x][i] != -1) {
            int e = trie[x][i];
            if(player[e][!id]) {
                bool v = dfs(e, !id);
                if(v) out = false;
            }
        }
    }
    return out;
}

int main() {
    // usaco();
    int n;
    cin >> n;
    frange(i, 200005) {
        frange(j, 26) trie[i][j] = -1;
        frange(j, 2) player[i][j] = false;
    }
    frange(i, n) {
        string str;
        cin >> str;
        add(str, 0);
    }
    int m;
    cin >> m;
    frange(i, m) {
        string str;
        cin >> str;
        add(str, 1);
    }
    if(!dfs(0, 1)) printf("Nina");
    else printf("Emilija");
}
