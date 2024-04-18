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
vvi vec;

int check(int x, int y, int x1, int y1, int ch) {
    if(x >= m || y >= n || x < 0 || y < 0 || vec[y][x] != ch) return 0;
    // printf("%d\n", check(x+x1, y+y1, x1, y1, ch) + 1);
    return check(x+x1, y+y1, x1, y1, ch) + 1;
}

int main() {
    // usaco();
    cin >> n >> m;

    vec = vvi(n, vi(m));
    vii val;
    frange(i, n) {
        string str;
        cin >> str;

        frange(j, m) {
            if(str[j] == '/') vec[i][j] = 1;
            if((int)str[j] == 92) vec[i][j] = 2;
            if(str[j] == '|') vec[i][j] = 3;
            if(str[j] == '-') vec[i][j] = 4;
            if(str[j] == '+') val.pb(mp(i, j));
        }
    }
    int ma = 0;
    for(auto p : val) {
        int v = 1000;
        v = min(v, check(p.s+1, p.f+1, 1, 1, 2));
        // printf("%d ", check(p.s+1, p.f+1, 1, 1, 2));
        // printf("%d ", check(p.s-1, p.f-1, -1, -1, 2));
        // printf("%d ", check(p.s+1, p.f-1, 1, -1, 1));
        // printf("%d ", check(p.s-1, p.f+1, -1, 1, 1));
        // printf("%d ", check(p.s, p.f+1, 0, 1, 3));
        // printf("%d ", check(p.s, p.f-1, 0, -1, 3));
        // printf("%d ", check(p.s+1, p.f, 1, 0, 4));
        // printf("%d ", check(p.s-1, p.f, -1, 0, 4));
        v = min(v, check(p.s-1, p.f-1, -1, -1, 2));
        v = min(v, check(p.s+1, p.f-1, 1, -1, 1));
        v = min(v, check(p.s-1, p.f+1, -1, 1, 1));
        v = min(v, check(p.s, p.f+1, 0, 1, 3));
        v = min(v, check(p.s, p.f-1, 0, -1, 3));
        v = min(v, check(p.s+1, p.f, 1, 0, 4));
        v = min(v, check(p.s-1, p.f, -1, 0, 4));
        ma = max(ma, v);
    }

    printf("%d", ma);
}