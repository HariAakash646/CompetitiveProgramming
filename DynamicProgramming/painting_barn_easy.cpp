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

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    vvi diff(1003, vi(1003, 0));
    vvi vec(1003, vi(1003, 0));

    int n, k;
    scd(n);
    scd(k);
    int x1, y1, x2, y2;
    frange(i, n)
    {
        scd(x1);
        scd(y1);
        scd(x2);
        scd(y2);
        x1++;
        x2++;
        y1++;
        y2++;
        diff[x1][y1]++;
        diff[x1][y2]--;
        diff[x2][y1]--;
        diff[x2][y2]++;
    }
    int c = 0;
    forr(i, 1, 1002, 1)
    {
        forr(j, 1, 1002, 1)
        {
            vec[i][j] = diff[i][j] + vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
            if (vec[i][j] == k)
                c++;
        }
    }

    cout << c;
    return 0;
}