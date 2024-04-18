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
    int n;
    cin >> n;
    vvi grid(n + 1, vi(n + 1));
    frange(i, n)
    {
        string row;
        cin >> row;
        frange(j, n) grid[i + 1][j + 1] = row[j] - '0';
    }

    vvi out(n + 1, vi(n + 1));

    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            out[i][j] = (grid[i][j] - grid[i - 1][j] - grid[i][j - 1] + grid[i - 1][j - 1] + 8) % 2;
            cout << out[i][j] << "";
        }
        cout << "\n";
    }
}