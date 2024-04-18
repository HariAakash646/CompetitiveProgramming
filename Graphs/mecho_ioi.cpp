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

int main()
{
    int n, k;
    scd(n);
    scd(k);

    vvi grid(n, vi(n));
    pii pos;
    queue<pair<pii, int>> q1, q2;
    vii vec;
    frange(i, n)
    {
        string str;
        cin >> str;
        frange(j, n)
        {
            if (str[j] == 'G')
                grid[i][j] = 1;
            if (str[j] == 'H')
                vec.pb({i, j});
            if (str[j] == 'M')
            {
                grid[i][j] = 1;
                q1.push(mp(mp(i, j), 0));
            }
            if (str[j] == 'D')
                pos = {i, j};
        }
    }
    while (hi != lo)
    {
        grid[pos.f][pos.s] = 1;
        vvi dist1(n, vi(n, 1e9)), dist2(n, vi(n, 1e9));

        vector<vb> vis(n, vb(n));
        while (q1.size())
        {
            auto p = q1.front();
            q1.pop();
            int i = p.f.f;
            int j = p.f.s;
            if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || !grid[i][j])
                continue;
            vis[i][j] = true;
            dist1[i][j] = min(dist1[i][j], (p.s + k) / k);
            q1.push(mp(mp(i + 1, j), p.s + 1));
            q1.push(mp(mp(i, j + 1), p.s + 1));
            q1.push(mp(mp(i, j - 1), p.s + 1));
            q1.push(mp(mp(i - 1, j), p.s + 1));
        }
        // grid[pos.f][pos.s] = 0;
        for (auto p : vec)
        {
            grid[p.f][p.s] = 1;
            q2.push(mp(mp(p.f, p.s), 0));
        }
        vis = vector<vb>(n, vb(n));
        while (q2.size())
        {
            auto p = q2.front();
            q2.pop();
            int i = p.f.f;
            int j = p.f.s;
            if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || !grid[i][j])
                continue;
            vis[i][j] = true;
            dist2[i][j] = min(dist2[i][j], p.s);
            q2.push(mp(mp(i + 1, j), p.s + 1));
            q2.push(mp(mp(i, j + 1), p.s + 1));
            q2.push(mp(mp(i, j - 1), p.s + 1));
            q2.push(mp(mp(i - 1, j), p.s + 1));
        }
        int mi = dist2[pos.f][pos.s] - dist1[pos.f][pos.s];
    }
    printf("%d %d\n", dist1[pos.f][pos.s], dist2[pos.f][pos.s]);
    // int mi = -min({dist1[pos.f - 1][pos.s] - dist2[pos.f - 1][pos.s], dist1[pos.f + 1][pos.s] - dist2[pos.f + 1][pos.s], dist1[pos.f][pos.s - 1] - dist2[pos.f][pos.s - 1], dist1[pos.f][pos.s + 1] - dist2[pos.f][pos.s + 1]});
    if (mi >= 0)
        printf("%d", mi);
    else
        printf("-1");
}