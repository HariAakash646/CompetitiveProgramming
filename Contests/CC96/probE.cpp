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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        if (k % 2 == 0)
        {
            if (n % 2 == 0)
            {
                printf("Bob\n");
                fflush(stdout);
                int x;
                scd(x);
                n = x;
            }
            else
            {
                printf("Alice\n");
                fflush(stdout);
            }
            while (true)
            {
                printf("1\n");
                fflush(stdout);
                int x;
                scd(x);
                if (x == 0)
                    break;
                if (x == -1)
                    return 0;
            }
        }
        else
        {
            if (gcd(k, n) == 1)
            {
                printf("Alice\n");
                fflush(stdout);
                printf("%d\n", n);
                fflush(stdout);
                int x;
                scd(x);
                if (x != 0)
                    return 0;
            }
            else
            {
                bool done = false;
                forr(i, 1, n)
                {
                    if (gcd(i, k) == 1 && gcd(n - i, k) != 1)
                    {
                        printf("Alice\n");
                        fflush(stdout);
                        done = true;
                        printf("%d\n", i);
                        fflush(stdout);
                        break;
                    }
                }
                if (!done)
                {
                    printf("Bob\n");
                    fflush(stdout);
                }

                while (true)
                {
                    int x;
                    scd(x);
                    n = x;
                    if (x == 0)
                        break;
                    if (x == -1)
                        return 0;
                    if (gcd(n, k) == 1)
                    {
                        printf("%d\n", n);
                        fflush(stdout);
                    }
                    else
                    {
                        bool done = false;
                        forr(i, 1, n)
                        {
                            if (gcd(i, k) == 1 && gcd(n - i, k) != 1)
                            {
                                printf("%d\n", i);
                                fflush(stdout);
                                done = true;
                                break;
                            }
                        }
                        if (!done)
                            return -1;
                    }
                }
            }
        }
    }
}