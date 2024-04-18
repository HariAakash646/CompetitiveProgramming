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
    int n, c, p;
    cin >> n >> c >> p;
    c--;
    vector<string> vec(n);
    frange(i, n) cin >> vec[i];
    vector<vector<vll>> mdp(n, vector<vll>(n, vll(n + 1)));
    vector<vb> row(n, vb(n));
    frange(l, n) row[l][l] = true;
    forr(l, 1, n)
    {
        for (int i = 0; i + l < n; i++)
        {
            bool done = false;
            if (row[i + 1][i + l])
            {
                frange(j, n)
                {
                    if (vec[j][i + 1] == vec[j][i])
                    {
                        done = true;
                        break;
                    }
                }
            }
            if (row[i][i + l - 1])
            {
                frange(j, n)
                {
                    if (vec[j][i + l - 1] == vec[j][i + l])
                    {
                        done = true;
                        break;
                    }
                }
            }
            if (done)
                row[i][i + l] = true;
        }
    }

    vvi rowma(n, vi(n));
    frange(i, n) rowma[i][i] = 1;
    forr(l, 1, n)
    {
        for (int i = 0; i + l < n; i++)
        {
            if (row[i][i + l])
                rowma[i][i + l] = l + 1;
            else
                rowma[i][i + l] = max(rowma[i + 1][i + l], rowma[i][i + l - 1]);
        }
    }
    // frange(i, n)
    // {
    //     frange(j, n)
    //     {
    //         printf("%d ", int(rowma[i][j]));
    //     }
    //     printf("\n");
    // }
    vi colma(n);
    frange(i, n)
    {
        int ma = 0;
        int curr = 1;
        forr(j, 1, n)
        {
            if (vec[j][i] != vec[j - 1][i])
            {
                ma = max(ma, curr);
                curr = 0;
            }
            curr++;
        }
        ma = max(ma, curr);
        colma[i] = ma;
    }
    // frange(i, n)
    // {
    //     printf("%d ", colma[i]);
    // }
    for (int l = n - 1; l >= 0; l--)
    {
        for (int i = 0; i + l < n; i++)
        {

            int ml = 0;
            for (int k = i; k <= i + l; k++)
            {
                ml = max(ml, colma[k]);
            }
            ml = max(ml, rowma[i][i + l]);
            // mdp[i][i + l] = lli(p1) * lli(ml) * lli(ml);
            int rlml = 0;
            if (i > 0)
            {
                rlml = colma[i];
                forr(j, i, i + l + 1)
                {
                    if (row[i][j])
                        rlml = max(rlml, j - i + 1);
                }
                // mdp[i][i + l] = max(mdp[i][i + l], mdp[i - 1][i + l] + lli(ml) * lli(ml));
            }
            int rrml = 0;
            if (i + l < n - 1)
            {
                rrml = colma[i + l];
                forr(j, i, i + l + 1)
                {
                    if (row[j][i + l])
                        rrml = max(rrml, (i + l) - j + 1);
                }
                // mdp[i][i + l] = max(mdp[i][i + l], mdp[i][i + l + 1] + lli(ml) * lli(ml));
            }
            frange(k, l + 1)
            {
                // printf("%d\n", k);
                int p1 = p - k;
                if (ml >= 3)
                    mdp[i][i + l][k] = p1 * lli(ml) * lli(ml);
                if (k == n)
                    continue;
                if (l == 0 && i > 0 && i + l < n - 1 && ml >= 3)
                {
                    mdp[i][i + l][k] = max(mdp[i][i + l][k], mdp[i - 1][i + l + 1][k + 1] + lli(ml) * lli(ml));
                }
                if (row[i][i + l] && i > 0 && i + l < n - 1 && l + 1 >= 3)
                {
                    mdp[i][i + l][k] = max(mdp[i][i + l][k], mdp[i - 1][i + l + 1][k + 1] + lli(l + 1) * lli(l + 1));
                }
                if (i > 0 && rlml >= 3)
                    mdp[i][i + l][k] = max(mdp[i][i + l][k], mdp[i - 1][i + l][k + 1] + lli(rlml) * lli(rlml));
                if (i + l < n - 1 && rrml >= 3)
                    mdp[i][i + l][k] = max(mdp[i][i + l][k], mdp[i][i + l + 1][k + 1] + lli(rrml) * lli(rrml));
            }
        }
    }
    if (n >= 3)
        cout << mdp[c][c][0];
    else
        cout << 0;
    // frange(i, n)
    // {
    //     frange(j, n)
    //     {
    //         printf("%d ", int(mdp[i][j]));
    //     }
    //     printf("\n");
    // }
}