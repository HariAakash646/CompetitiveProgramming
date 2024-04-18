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

int n, m;

bool cor(int x, int y)
{
    if ((x == 1 || x == n) && (y == 1 || y == m))
        return true;
    else
        return false;
}

bool edge(int x, int y)
{
    if (x == 1 || x == n)
    {
        return true;
    }
    else if (y == 1 || y == m)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        scd(m);
        int x1, y1, x2, y2;
        scd(x1);
        scd(y1);
        scd(x2);
        scd(y2);
        if (cor(x1, y1) || cor(x2, y2))
        {
            printf("2\n");
        }
        else if (edge(x1, y1) || edge(x2, y2))
        {
            printf("3\n");
        }
        else
        {
            printf("4\n");
        }
    }
}