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

int direc(string dir)
{
    if (dir == "DR")
        return 1;
    if (dir == "DL")
        return 2;
    if (dir == "UR")
        return 3;
    if (dir == "UL")
        return 4;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int n, m;
        cin >> n >> m;
        int i1, j1, i2, j2;
        string dir;
        cin >> i1 >> j1 >> i2 >> j2 >> dir;
        int c = 0;
        int x = i1;
        int y = j1;
        set<pair<pii, int>> pos;
        pos.insert(mp(mp(i1, j1), direc(dir)));
        int corn = 0;
        bool done = false;
        while (true)
        {
            int px = x;
            int py = y;
            int pd = direc(dir);
            if (direc(dir) == 1)
            {
                if ((n - x < m - y))
                {
                    y += n - x;
                    x = n;
                    dir = "UR";
                }
                else if (n - x > m - y)
                {
                    x += m - y;
                    y = m;
                    dir = "DL";
                }
                else
                {
                    y = m;
                    x = n;
                    dir = "UL";
                    corn++;
                }
            }
            else if (direc(dir) == 2)
            {
                if ((n - x < y - 1))
                {
                    y -= n - x;
                    x = n;
                    dir = "UL";
                }
                else if (n - x > y - 1)
                {
                    x += y - 1;
                    y = 1;
                    dir = "DR";
                }
                else
                {
                    y = 1;
                    x = n;
                    dir = "UR";
                    corn++;
                }
            }
            else if (direc(dir) == 3)
            {
                if ((x - 1 < m - y))
                {
                    y += x - 1;
                    x = 1;
                    dir = "DR";
                }
                else if (x - 1 > m - y)
                {
                    x -= m - y;
                    y = m;
                    dir = "UL";
                }
                else
                {
                    y = m;
                    x = 1;
                    dir = "DL";
                    corn++;
                }
            }
            else if (direc(dir) == 4)
            {
                if ((x - 1 < y - 1))
                {
                    y -= x - 1;
                    x = 1;
                    dir = "DL";
                }
                else if (x - 1 > y - 1)
                {
                    x -= y - 1;
                    y = 1;
                    dir = "UR";
                }
                else
                {
                    y = 1;
                    x = 1;
                    dir = "DR";
                    corn++;
                }
            }
            // if (x == i2 && y == j2)
            // {
            //     printf("%d\n", c + 1);
            //     done = true;
            //     break;
            // }
            // cout << x << " " << y << " " << dir << "\n";
            if (pd == 1)
            {
                if (i2 - px == j2 - py && (i2 - px >= 0))
                {
                    printf("%d\n", c);
                    done = true;
                    break;
                }
            }
            else if (pd == 4)
            {
                if (i2 - px == j2 - py && (i2 - px <= 0))
                {
                    printf("%d\n", c);
                    done = true;
                    break;
                }
            }
            else if (pd == 2)
            {
                if (i2 - px == py - j2 && ((i2 - px >= 0)))
                {
                    printf("%d\n", c);
                    done = true;
                    break;
                }
            }
            else if (pd == 3)
            {
                if (i2 - px == py - j2 && ((i2 - px <= 0)))
                {
                    printf("%d\n", c);
                    done = true;
                    break;
                }
            }
            if (pos.find(mp(mp(x, y), direc(dir))) != pos.end())
            {
                printf("-1\n");
                done = true;
                break;
            }
            pos.insert(mp(mp(x, y), direc(dir)));
            c++;
        }
    }
}