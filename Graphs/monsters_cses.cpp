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

vector<vii> mons;
vector<vb> vis1;
string out = "";
int n, m;

bool dfs(pii curr, pii pos)
{
    int i = curr.f;
    int j = curr.s;
    if (curr == pos)
        return true;
    if (i < 0 || j < 0 || i >= n || j >= m || vis1[i][j] || mons[i][j].s)
        return false;
    vis1[i][j] = true;
    if (dfs({i + 1, j}, pos))
    {
        out += "L";
        return true;
    }
    if (dfs({i, j + 1}, pos))
    {
        out += "U";
        return true;
    }
    if (dfs({i - 1, j}, pos))
    {
        out += "R";
        return true;
    }
    if (dfs({i, j - 1}, pos))
    {
        out += "D";
        return true;
    }
    return false;
}

int main()
{

    scd(n);
    scd(m);
    string a;
    vvi grid(n, vi(m));
    queue<pair<pii, pii>> q;
    pii pos;
    frange(i, n)
    {
        cin >> a;
        frange(j, m)
        {
            if (a[j] == '#')
                grid[i][j] = -1;
            else if (a[j] == 'M')
                q.push(mp(mp(i, j), mp(0, 0)));
            else if (a[j] == 'A')
                pos = mp(i, j);
        }
    }
    q.push(mp(pos, mp(0, 1)));
    vector<vb> vis(n, vb(m));
    mons = vector<vii>(n, vii(m, {1e9, 1}));
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int i = p.f.f;
        int j = p.f.s;
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == -1)
            continue;
        vis[i][j] = true;
        if (p.s.f < mons[i][j].f)
        {
            mons[i][j] = p.s;
        }
        else if (p.s.f == mons[i][j].f)
        {
            if (p.s.s == 1)
                mons[i][j] = p.s;
        }

        q.push(mp(mp(p.f.f, p.f.s + 1), mp(p.s.f + 1, p.s.s)));
        q.push(mp(mp(p.f.f, p.f.s - 1), mp(p.s.f + 1, p.s.s)));
        q.push(mp(mp(p.f.f + 1, p.f.s), mp(p.s.f + 1, p.s.s)));
        q.push(mp(mp(p.f.f - 1, p.f.s), mp(p.s.f + 1, p.s.s)));
    }
    vis1 = vector<vb>(n, vb(m));
    frange(i, n)
    {
        if (!mons[i][0].s)
        {
            printf("YES\n");
            dfs({i, 0}, pos);
            cout << out.size() << "\n"
                 << out;
            return 0;
        }
    }
    frange(i, n)
    {
        if (!mons[i][m - 1].s)
        {
            printf("YES\n");
            dfs({i, m - 1}, pos);
            cout << out.size() << "\n"
                 << out;
            return 0;
        }
    }
    frange(i, m)
    {
        if (!mons[0][i].s)
        {
            printf("YES\n");
            dfs({0, i}, pos);
            cout << out.size() << "\n"
                 << out;
            return 0;
        }
    }
    frange(i, m)
    {
        if (!mons[n - 1][i].s)
        {
            printf("YES\n");
            dfs({n - 1, i}, pos);
            cout << out.size() << "\n"
                 << out;
            return 0;
        }
    }
    printf("NO");
}