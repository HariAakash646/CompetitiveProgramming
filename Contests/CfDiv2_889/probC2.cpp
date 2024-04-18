#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
        int n;
        scd(n);
        vi vec(n + 1);
        int ma = 0;
        int mi = -1;
        int pos = 0;
        int neg = 0;
        int zer = 0;
        int sig = 1;
        // int k;
        forr(i, 1, n + 1)
        {
            scd(vec[i]);
            if (vec[i] > 0)
                pos++;
            if (vec[i] < 0)
                neg++;
            if (vec[i] == 0)
                zer++;
            if (abs(vec[i]) >= ma)
            {
                ma = abs(vec[i]);
                mi = i;
                if (vec[i] >= 0)
                    sig = 1;
                else
                    sig = -1;
            }
        }
        if (zer == n)
        {
            printf("0\n");
        }
        else if (pos >= neg)
        {

            if (sig == 1)
            {
                int k = (neg + n - 1);
                printf("%d\n", k);
                forr(i, 1, n + 1)
                {
                    if (vec[i] < 0)
                    {
                        printf("%d %d\n", i, mi);
                    }
                }
                forr(i, 2, n + 1)
                {
                    printf("%d %d\n", i, i - 1);
                }
            }
            else
            {
                if (pos - neg < 5)
                {
                    int k = (pos + n - 1);
                    printf("%d\n", k);
                    forr(i, 1, n + 1)
                    {
                        if (vec[i] > 0)
                        {
                            printf("%d %d\n", i, mi);
                        }
                    }
                    for (int i = n - 1; i >= 1; i--)
                    {
                        printf("%d %d\n", i, i + 1);
                    }
                }
                else
                {
                    int k = 5 + neg + n - 1;
                    printf("%d\n", k);
                    int mv = 0;
                    int id = 0;
                    forr(i, 1, n + 1)
                    {
                        if (vec[i] > mv)
                        {
                            mv = vec[i];
                            id = i;
                        }
                    }
                    frange(i, 5) printf("%d %d\n", id, id);
                    forr(i, 1, n + 1)
                    {
                        if (vec[i] < 0)
                            printf("%d %d\n", i, id);
                    }
                    forr(i, 2, n + 1)
                    {
                        printf("%d %d\n", i, i - 1);
                    }
                }
            }
        }
        else
        {
            if (sig == -1)
            {
                int k = (pos + n - 1);
                printf("%d\n", k);
                forr(i, 1, n + 1)
                {
                    if (vec[i] > 0)
                    {
                        printf("%d %d\n", i, mi);
                    }
                }
                for (int i = n - 1; i >= 1; i--)
                {
                    printf("%d %d\n", i, i + 1);
                }
            }
            else
            {
                if (neg - pos < 5)
                {
                    int k = (neg + n - 1);
                    printf("%d\n", k);
                    forr(i, 1, n + 1)
                    {
                        if (vec[i] < 0)
                        {
                            printf("%d %d\n", i, mi);
                        }
                    }
                    forr(i, 2, n + 1)
                    {
                        printf("%d %d\n", i, i - 1);
                    }
                }
                else
                {
                    int k = 5 + pos + n - 1;
                    printf("%d\n", k);
                    int mv = 0;
                    int id = 0;
                    forr(i, 1, n + 1)
                    {
                        if (vec[i] < mv)
                        {
                            mv = vec[i];
                            id = i;
                        }
                    }
                    frange(i, 5) printf("%d %d\n", id, id);
                    forr(i, 1, n + 1)
                    {
                        if (vec[i] > 0)
                            printf("%d %d\n", i, id);
                    }
                    for (int i = n - 1; i >= 1; i--)
                    {
                        printf("%d %d\n", i, i + 1);
                    }
                }
            }
        }
    }
}