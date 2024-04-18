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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
            {
                printf("%d %d ", vec[i + 1], -vec[i]);
            }
        }
        else
        {
            for (int i = 0; i < n - 3; i += 2)
            {
                printf("%d %d ", vec[i + 1], -vec[i]);
            }
            int a = vec[n - 3];
            int b = vec[n - 2];
            int c = vec[n - 1];
            if (a + b == 0)
            {
                int tmp = b;
                b = c;
                c = tmp;
                if (a + b == 0)
                {
                    int tmp = a;
                    a = c;
                    c = tmp;
                    printf("%d %d %d ", a + b, -c, -c);
                }
                else
                {
                    printf("%d %d %d ", -c, a + b, -c);
                }
            }
            else
            {
                printf("%d %d %d ", -c, -c, a + b);
            }
        }
        printf("\n");
    }
}