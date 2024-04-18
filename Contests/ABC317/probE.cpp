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

int main()
{
    int h, w;
    cin >> h >> w;

    vvi vec(h + 1, vi(w + 1));
    map<char, int> m;
    m['.'] = 0;
    m['#'] = 1;
    m['<'] = 2;
    m['>'] = 3;
    m['^'] = 4;
    m['v'] = 5;
    pii st, en;
    forr(i, 1, h + 1)
    {
        string row;
        cin >> row;
        forr(j, 1, w + 1)
        {
            if (row[j - 1] == 'S')
                st = {i, j};
            if (row[j - 1] == 'G')
                en = {i, j};
            vec[i][j] = m[row[j - 1]];
        }
    }

    vvi grid(h + 1, vi(w + 1));
    forr(i, 1, h + 1)
    {
        bool on = false;
        forr(j, 1, w + 1)
        {
            if (vec[i][j])
            {
                on = false;
                grid[i][j] = 1;
            }
            if (on)
                grid[i][j] = 1;
            if (vec[i][j] == 3)
                on = true;
        }
    }

    forr(i, 1, h + 1)
    {
        bool on = false;
        for (int j = w; j >= 1; j--)
        {
            if (vec[i][j])
            {
                on = false;
                grid[i][j] = 1;
            }
            if (on)
                grid[i][j] = 1;
            if (vec[i][j] == 2)
                on = true;
        }
    }

    forr(i, 1, w + 1)
    {
        bool on = false;
        forr(j, 1, h + 1)
        {
            if (vec[j][i])
            {
                on = false;
                grid[j][i] = 1;
            }
            if (on)
                grid[j][i] = 1;
            if (vec[j][i] == 5)
                on = true;
        }
    }

    forr(i, 1, w + 1)
    {
        bool on = false;
        for (int j = h; j >= 1; j--)
        {
            if (vec[j][i])
            {
                on = false;
                grid[j][i] = 1;
            }
            if (on)
                grid[j][i] = 1;
            if (vec[j][i] == 4)
                on = true;
        }
    }

    // forr(i, 1, h + 1)
    // {
    //     forr(j, 1, w + 1)
    //     {
    //         printf("%d ", grid[i][j]);
    //     }
    //     printf("\n");
    // }

    queue<pair<pii, int>> q;
    q.push(mp(st, 0));
    vector<vb> vis(h + 1, vb(w + 1));

    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int x = p.f.f;
        int y = p.f.s;
        // printf("%d %d\n", x, y);
        if (mp(x, y) == en)
        {
            printf("%d", p.s);
            return 0;
        }
        if (x > h || y > w || x < 1 || y < 1 || vis[x][y] || grid[x][y])
            continue;
        vis[x][y] = true;
        q.push(mp(mp(x + 1, y), p.s + 1));
        q.push(mp(mp(x - 1, y), p.s + 1));
        q.push(mp(mp(x, y + 1), p.s + 1));
        q.push(mp(mp(x, y - 1), p.s + 1));
    }

    printf("-1");
}