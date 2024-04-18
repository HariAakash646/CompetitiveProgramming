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
    int n, m, q;
    cin >> n >> m >> q;
    vvi vec(n, vi(m));
    int c = 0;
    frange(i, n)
    {
        string row;
        cin >> row;
        frange(j, m)
        {
            if (row[j] == '*')
            {
                vec[i][j] = 1;
                c++;
            }
        }
    }
    int co = c / n;
    int ro = c % n;
    frange(i, n)
    {
        frange(j, m)
        {
            if (vec[i][j])
            {
                if (j < co)
                    c--;
                else if (j == co && i < ro)
                    c--;
            }
        }
    }
    // printf("%d\n", c);
    frange(i, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (vec[x][y])
        {
            if (y > co)
                c--;
            else if (y == co && x >= ro)
                c--;
            vec[x][y] = 0;
            ro--;
            if (ro == -1)
            {
                co--;
                ro = n - 1;
            }
            if (vec[ro][co])
            {
                c++;
            }

            printf("%d\n", c);
        }
        else
        {
            ro++;
            if (vec[ro - 1][co])
            {
                c--;
            }
            if (ro == n)
            {
                co++;
                ro = 0;
            }
            vec[x][y] = 1;
            if (y > co)
                c++;
            else if (y == co && x >= ro)
                c++;
            printf("%d\n", c);
        }
    }
}