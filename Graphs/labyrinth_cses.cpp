#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, m;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vvi grid(n, vi(m));
    string c;
    pii start;
    pii fin;
    frange(i, n)
    {
        cin >> c;
        frange(j, m)
        {
            if (c[j] == '.')
            {
                grid[i][j] = 1;
            }
            else if (c[j] == '#')
            {
                grid[i][j] = 0;
            }
            else if (c[j] == 'A')
            {
                grid[i][j] = 1;
                start = {i, j};
            }
            else if (c[j] == 'B')
            {
                grid[i][j] = 1;
                fin = {i, j};
            }
        }
    }
    queue<pii> q;
    vector<vector<pair<char, int>>> data(n, vector<pair<char, int>>(m, {'N', 0}));
    q.push(start);
    data[start.f][start.s] = {'S', 1};
    while (q.size() != 0)
    {
        pii curr = q.front();
        q.pop();
        if (curr == fin)
        {
            break;
        }
        if (curr.f < n - 1 && grid[curr.f + 1][curr.s] == 1 && data[curr.f + 1][curr.s].s == 0)
        {
            q.push({curr.f + 1, curr.s});
            data[curr.f + 1][curr.s].f = 'D';
            data[curr.f + 1][curr.s].s = data[curr.f][curr.s].s + 1;
        }
        if (curr.f > 0 && grid[curr.f - 1][curr.s] == 1 && data[curr.f - 1][curr.s].s == 0)
        {
            q.push({curr.f - 1, curr.s});
            data[curr.f - 1][curr.s].f = 'U';
            data[curr.f - 1][curr.s].s = data[curr.f][curr.s].s + 1;
        }
        if (curr.s < m - 1 && grid[curr.f][curr.s + 1] == 1 && data[curr.f][curr.s + 1].s == 0)
        {
            q.push({curr.f, curr.s + 1});
            data[curr.f][curr.s + 1].f = 'R';
            data[curr.f][curr.s + 1].s = data[curr.f][curr.s].s + 1;
        }
        if (curr.s > 0 && grid[curr.f][curr.s - 1] == 1 && data[curr.f][curr.s - 1].s == 0)
        {
            q.push({curr.f, curr.s - 1});
            data[curr.f][curr.s - 1].f = 'L';
            data[curr.f][curr.s - 1].s = data[curr.f][curr.s].s + 1;
        }
    }
    string out = "";
    if (data[fin.f][fin.s].s == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << data[fin.f][fin.s].s - 1 << "\n";
        int x = fin.f;
        int y = fin.s;
        while (true)
        {
            char dir = data[x][y].f;
            if (dir == 'S')
                break;
            else if (dir == 'U')
                x++;
            else if (dir == 'D')
                x--;
            else if (dir == 'L')
                y++;
            else if (dir == 'R')
                y--;
            out += dir;
        }
        reverse(all(out));
        cout << out;
    }
    return 0;
}