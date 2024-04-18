#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

vector<string> grid;
string str = "snuke";
int h, w;
vector<vb> vis;

bool dfs(pii x, int t)
{
    if (x.f >= h || x.f < 0 || x.s >= w || x.s < 0)
        return false;

    if (grid[x.f][x.s] != str[t % 5])
    {
        return false;
    }
    if (x.f == h - 1 && x.s == w - 1)
        return true;
    if (vis[x.f][x.s])
        return false;
    vis[x.f][x.s] = true;
    bool out = dfs({x.f + 1, x.s}, t + 1);
    out = (out || dfs({x.f - 1, x.s}, t + 1));
    out = (out || dfs({x.f, x.s + 1}, t + 1));
    out = (out || dfs({x.f, x.s - 1}, t + 1));
    return out;
}

int main()
{

    cin >> h >> w;
    grid = vector<string>(h);
    frange(i, h) cin >> grid[i];
    vis = vector<vb>(h, vb(w));
    bool out = dfs({0, 0}, 0);
    if (out)
        printf("Yes");
    else
        printf("No");
}