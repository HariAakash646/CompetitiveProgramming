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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int t;
    cin >> t;

    frange(_, t)
    {
        int n, m;
        cin >> n >> m;
        vvi vec(n + 1, vi(m + 1));

        map<char, int> con;
        con['L'] = 1;
        con['R'] = 2;
        con['U'] = 3;
        con['D'] = 4;
        con['.'] = 0;

        forr(i, 1, n + 1)
        {
            string row;
            cin >> row;
            forr(j, 1, m + 1)
            {
                vec[i][j] = con[row[j - 1]];
            }
        }
        vvi out(n + 1, vi(m + 1, -1));
        forr(i, 1, n)
        {
            int v = 1;
            forr(j, 1, m + 1)
            {
                if (vec[i][j] == 3)
                {
                    out[i][j] = v;
                    v = !v;
                }
            }
        }
        forr(i, 2, n + 1)
        {
            forr(j, 1, m + 1)
            {
                if (vec[i][j] == 4)
                    out[i][j] = !out[i - 1][j];
            }
        }
        forr(j, 1, m)
        {
            int v = 1;
            forr(i, 1, n + 1)
            {
                if (vec[i][j] == 1)
                {
                    out[i][j] = v;
                    v = !v;
                }
            }
        }

        forr(j, 2, m + 1)
        {
            forr(i, 1, n + 1)
            {
                if (vec[i][j] == 2)
                {
                    out[i][j] = !out[i][j - 1];
                }
            }
        }

        bool done = true;
        forr(i, 1, n + 1)
        {
            int w = 0;
            int b = 0;
            forr(j, 1, m + 1)
            {
                if (out[i][j] == 1)
                    b++;
                else if (out[i][j] == 0)
                    w++;
            }
            if (w != b)
            {
                done = false;
            }
        }

        forr(j, 1, m + 1)
        {
            int w = 0;
            int b = 0;
            forr(i, 1, n + 1)
            {
                if (out[i][j] == 1)
                    b++;
                else if (out[i][j] == 0)
                    w++;
            }
            if (w != b)
            {
                done = false;
            }
        }

        if (done)
        {
            forr(i, 1, n + 1)
            {
                forr(j, 1, m + 1)
                {
                    if (out[i][j] == 0)
                        cout << 'W';
                    else if (out[i][j] == 1)
                        cout << 'B';
                    else
                        cout << '.';
                }
                cout << "\n";
            }
        }
        else
            cout << "-1\n";
    }
}