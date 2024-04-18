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
        int x, d;
        scd(x);
        scd(d);
        int c = 0;
        while (x % d == 0)
        {
            x /= d;
            c++;
        }
        if (c == 2)
        {
            bool prime = true;
            forr(i, 2, sqrt(x) + 1)
            {
                if (x % i == 0)
                    prime = false;
            }
            if (!prime)
            {
                printf("YES\n");
                continue;
            }
        }
        else if (c > 2)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
}