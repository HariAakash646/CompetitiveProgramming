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
#define PB push_back
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

    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    scd(n);
    vvi vec(n, vi(n));
    string a;
    frange(i, n)
    {
        cin >> a;
        frange(j, n)
        {
            vec[i][j] = a[j] - '0';
        }
    }
    int c = n - 1;
    int r = n - 1;
    int flip = 0;
    while (c > 0 and r > 0)
    {
        if (vec[r][c] == 1)
        {
            flip++;
            frange(i, r + 1)
            {
                frange(j, c + 1)
                {
                    vec[i][j] = abs(vec[i][j] - 1);
                }
            }
        }
        for (int k = r; k > 0; k--)
        {
            if (vec[k - 1][c] == 1)
            {
                flip++;
                frange(i, k)
                {
                    frange(j, c + 1)
                    {
                        vec[i][j] = abs(vec[i][j] - 1);
                    }
                }
            }
        }
        for (int k = c; k > 0; k--)
        {
            if (vec[r][k - 1] == 1)
            {
                flip++;
                frange(i, r + 1)
                {
                    frange(j, k)
                    {
                        vec[i][j] = abs(vec[i][j] - 1);
                    }
                }
            }
        }

        c--;
        r--;
    }
    if (vec[0][0] == 1)
        flip++;
    cout << flip;

    return 0;
}