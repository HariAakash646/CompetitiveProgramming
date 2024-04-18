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
    // int t;
    // scd(t);
    // frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n + 1);
        int ma = 0;
        int mi = -1;
        int sig = 1;

        forr(i, 1, n + 1)
        {
            scd(vec[i]);
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
        int k = 2 * (n - 1);
        printf("%d\n", k);
        forr(i, 1, n + 1)
        {
            if (i != mi)
            {
                vec[i] += sig * ma;
                printf("%d %d\n", i, mi);
            }
        }
        // k += n-1;
        if (sig == 1)
        {
            forr(i, 2, n + 1) printf("%d %d\n", i, i - 1);
        }
        else
        {
            for (int i = n - 1; i >= 1; i--)
                printf("%d %d\n", i, i + 1);
        }
    }
}