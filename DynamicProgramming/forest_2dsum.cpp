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

    int n, q;
    scd(n);
    scd(q);
    vvi vec(n + 1, vi(n + 1, 0));
    string a;
    int b;
    forr(i, 1, n + 1, 1)
    {
        cin >> a;
        forr(j, 1, n + 1, 1)
        {
            b = (a[j - 1] == '*') ? 1 : 0;
            vec[i][j] = vec[i - 1][j] + vec[i][j - 1] + b - vec[i - 1][j - 1];
        }
    }
    int y1, x1, y2, x2;
    frange(i, q)
    {
        scd(y1);
        scd(x1);
        scd(y2);
        scd(x2);
        cout << (vec[y2][x2] - vec[y1 - 1][x2] - vec[y2][x1 - 1] + vec[y1 - 1][x1 - 1]) << "\n";
    }

    return 0;
}