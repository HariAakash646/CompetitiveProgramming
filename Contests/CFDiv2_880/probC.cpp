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
    int t;
    scd(t);
    frange(_, t)
    {
        int a, b, c;
        lli k;
        scd(a);
        scd(b);
        scd(c);
        sclld(k);
        k--;
        if (a == b)
        {
            int c1 = pow(10, c) - 1;
            int a1 = pow(10, a - 1);
            if (c == a)
            {
                int v = 9 * pow(10, c - 1) - 1;
                forr(i, a1, c1)
                {
                    k -= v;
                    if (k < 0)
                    {
                        // printf("%d %d\n", k, v);
                        k += v;
                        break;
                    }
                    a1++;
                    v--;
                }
                int b1 = pow(10, b - 1);
                if (k > pow(10, b) - b1)
                {
                    printf("-1\n");
                    continue;
                }
                frange(i, k) b1++;
                if (a1 + b1 >= pow(10, c))
                {
                    printf("-1\n");
                    continue;
                }
                printf("%d + %d = %d\n", a1, b1, a1 + b1);
            }
            else if (c == a + 1)
            {
                c1 = pow(10, c - 1);
                int v = pow(10, c - 2);
                forr(i, a1, c1)
                {
                    k -= v;
                    if (k < 0)
                    {
                        k += v;
                        break;
                    }
                    a1++;
                    v++;
                }
                int b1 = c1 - a1;
                if (k > pow(10, b) - b1)
                {
                    printf("-1\n");
                    continue;
                }
                frange(i, k) b1++;
                if (a1 + b1 >= pow(10, c))
                {
                    printf("-1\n");
                    continue;
                }
                printf("%d + %d = %d\n", a1, b1, a1 + b1);
            }
            else
            {
                printf("-1\n");
                continue;
            }
        }
        else if (a > b)
        {
            int c1 = pow(10, c) - 1;
            int a1 = pow(10, a - 1);
            int b1 = pow(10, b - 1);
            if (c == a)
            {
                int v = 9 * pow(10, b - 1);
                forr(i, a1, c1)
                {
                    k -= v;
                    if (k < 0)
                    {
                        k += v;
                        break;
                    }
                    a1++;
                    if (c1 - a1 < b1)
                    {
                        b1--;
                        v--;
                    }
                }

                if (k > pow(10, b) - b1)
                {
                    printf("-1\n");
                    continue;
                }
                frange(i, k) b1++;
                if (a1 + b1 >= pow(10, c))
                {
                    printf("-1\n");
                    continue;
                }
                printf("%d + %d = %d\n", a1, b1, a1 + b1);
            }
            else if (c == a + 1)
            {
                c1 = pow(10, c - 1);
                b1 = pow(10, b) - 1;
                a1 = c1 - b1;
                int v = 1;
                forr(i, a1, c1)
                {
                    k -= v;
                    if (k < 0)
                    {
                        k += v;
                        break;
                    }
                    a1++;
                    v++;
                }
                b1 = c1 - a1;
                if (k > pow(10, b) - b1)
                {
                    printf("-1\n");
                    continue;
                }
                frange(i, k) b1++;
                if (a1 + b1 >= pow(10, c))
                {
                    printf("-1\n");
                    continue;
                }
                printf("%d + %d = %d\n", a1, b1, a1 + b1);
            }
            else
            {
                printf("-1\n");
                continue;
            }
        }
        else
        {
            int c1 = pow(10, c) - 1;
            int a1 = pow(10, a - 1);
            int b1 = pow(10, b - 1);
            if (c == b)
            {
                int v = pow(10, c) - pow(10, a - 1);
                forr(i, a1, pow(10, a))
                {
                    k -= v;
                    if (k < 0)
                    {
                        k += v;
                        break;
                    }
                    a1++;
                    v--;
                }

                if (k > pow(10, b) - b1)
                {
                    printf("-1\n");
                    continue;
                }
                frange(i, k) b1++;
                if (a1 + b1 >= pow(10, c))
                {
                    printf("-1\n");
                    continue;
                }
                printf("%d + %d = %d\n", a1, b1, a1 + b1);
            }
            else if (c == b + 1)
            {
                c1 = pow(10, c - 1);
                a1 = pow(10, a - 1);
                int v = a1;
                forr(i, a1, pow(10, a))
                {
                    k -= v;
                    if (k < 0)
                    {
                        k += v;
                        break;
                    }
                    a1++;
                    v++;
                }
                b1 = c1 - a1;
                if (k > pow(10, b) - b1)
                {
                    printf("-1\n");
                    continue;
                }
                frange(i, k) b1++;
                if (a1 + b1 >= pow(10, c))
                {
                    printf("-1\n");
                    continue;
                }
                printf("%d + %d = %d\n", a1, b1, a1 + b1);
            }
            else
            {
                printf("-1\n");
                continue;
            }
        }
    }
}