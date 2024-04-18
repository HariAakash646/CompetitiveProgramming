// Not working :(
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

vector<vector<vii>> vec;
vector<vb> vis;

void dfs(int x, int y)
{
    if (vis[x][y])
        return;
    vis[x][y] = true;
    // if (x > 0)
    //     dfs(x - 1, y);
    // if (y > 0)
    //     dfs(x, y - 1);
    // if (x < 1000)
    //     dfs(x + 1, y);
    // if (y < 1000)
    //     dfs(x, y + 1);
    for (auto p : vec[x][y])
    {
        dfs(p.f, p.s);
    }
}

int main()
{
    int n;
    scd(n);
    vec = vector<vector<vii>>(1001, vector<vii>(1001));
    vis = vector<vb>(1001, vb(1001));
    frange(i, 1001)
    {
        frange(j, 1001)
        {
            if (i > 0)
            {
                vec[i][j].pb({i - 1, j});
            }
            if (j > 0)
            {
                vec[i][j].pb({i, j - 1});
            }
            if (i < 1000)
            {
                vec[i][j].pb({i + 1, j});
            }
            if (j < 1000)
            {
                vec[i][j].pb({i, j + 1});
            }
        }
    }
    string seq;
    cin >> seq;
    pii cur = {500, 500};
    for (auto e : seq)
    {
        if (e == 'N')
        {
            if (cur.f > 0)
            {
                auto it1 = find(all(vec[cur.f][cur.s]), mp(cur.f - 1, cur.s));
                auto it2 = find(all(vec[cur.f - 1][cur.s]), mp(cur.f, cur.s));
                if (it1 != vec[cur.f][cur.s].end())
                    vec[cur.f][cur.s].erase(it1);
                if (it2 != vec[cur.f - 1][cur.s].end())
                    vec[cur.f - 1][cur.s].erase(it2);
            }
            cur.s++;
        }
        if (e == 'S')
        {
            cur.s--;
            if (cur.f > 0)
            {
                auto it1 = find(all(vec[cur.f][cur.s]), mp(cur.f - 1, cur.s));
                auto it2 = find(all(vec[cur.f - 1][cur.s]), mp(cur.f, cur.s));
                if (it1 != vec[cur.f][cur.s].end())
                    vec[cur.f][cur.s].erase(it1);
                if (it2 != vec[cur.f - 1][cur.s].end())
                    vec[cur.f - 1][cur.s].erase(it2);
            }
        }
        if (e == 'E')
        {
            if (cur.s > 0)
            {
                auto it1 = find(all(vec[cur.f][cur.s]), mp(cur.f, cur.s - 1));
                auto it2 = find(all(vec[cur.f][cur.s - 1]), mp(cur.f, cur.s));
                if (it1 != vec[cur.f][cur.s].end())
                    vec[cur.f][cur.s].erase(it1);
                if (it2 != vec[cur.f][cur.s - 1].end())
                    vec[cur.f][cur.s - 1].erase(it2);
            }
            cur.f++;
        }
        if (e == 'W')
        {
            cur.f--;
            if (cur.s > 0)
            {
                auto it1 = find(all(vec[cur.f][cur.s]), mp(cur.f, cur.s - 1));
                auto it2 = find(all(vec[cur.f][cur.s - 1]), mp(cur.f, cur.s));
                if (it1 != vec[cur.f][cur.s].end())
                    vec[cur.f][cur.s].erase(it1);
                if (it2 != vec[cur.f][cur.s - 1].end())
                    vec[cur.f][cur.s - 1].erase(it2);
            }
        }
    }
    int c = 0;
    frange(i, 1001)
    {
        frange(j, 1001)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                c++;
            }
        }
    }
    printf("%d", c);
}