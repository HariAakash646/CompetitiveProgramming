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

void usaco()
{
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vvi grid(n + 1, vi(m + 1));
    frange(i, n)
    {
        string row;
        cin >> row;
        frange(j, m) grid[i + 1][j + 1] = row[j] - '0';
    }

    vvi pref(n + 1, vi(m + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
        }
    }
    vvi hor(n + 1, vi(m));
    vvi vert(n, vi(m + 1));
    forr(i, 1, n + 1)
    {
        forr(j, 1, m)
        {
            hor[i][j] = hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
            if (grid[i][j] && grid[i][j + 1])
                hor[i][j]++;
        }
    }

    forr(i, 1, n)
    {
        forr(j, 1, m + 1)
        {
            vert[i][j] = vert[i - 1][j] + vert[i][j - 1] - vert[i - 1][j - 1];
            if (grid[i][j] && grid[i + 1][j])
                vert[i][j]++;
        }
    }

    frange(i, q)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int vertice = pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1];
        int edges = (hor[x2][y2 - 1] - hor[x2][y1 - 1] - hor[x1 - 1][y2 - 1] + hor[x1 - 1][y1 - 1]) + (vert[x2 - 1][y2] - vert[x2 - 1][y1 - 1] - vert[x1 - 1][y2] + vert[x1 - 1][y1 - 1]);
        cout << vertice - edges << "\n";
    }
}