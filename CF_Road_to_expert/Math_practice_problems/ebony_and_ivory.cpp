// Not working with Linear Diophantine Equations
// Simple brute force soluion available though.

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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int main()
{
    int a, b, c;
    scd(a);
    scd(b);
    scd(c);
    int x, y;
    if (b > a)
        swap(a, b);
    int g = gcd(a, b, x, y);
    if (c % g)
        printf("No\n");
    else
    {
        int x0 = x * (c / g);
        int y0 = y * (c / g);
        if (x0 < 0 && y0 < 0)
        {
            printf("No\n");
        }
        else if (x0 < 0)
        {
            int k1 = (abs(x0) * g) / b;
            int k2 = (y0 * g) / a;
            int k = -((-g * y0) / a) - ((-g * x0) / b) - 1;
            if (k <= 0)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else if (y0 < 0)
        {
            int k1 = (x0 * g) / b;
            int k2 = (abs(y0) * g) / a;
            int k = -((-g * y0) / a) - ((-g * x0) / b) - 1;
            if (k <= 0)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}