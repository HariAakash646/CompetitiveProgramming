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
        int x, y, n;
        scd(x);
        scd(y);
        scd(n);
        vi vec(n);
        vec[0] = x;
        forr(i, 1, n)
        {
            vec[i] = vec[i - 1] + n - i;
        }
        if (vec[n - 1] > y)
        {
            printf("-1\n");
        }
        else
        {
            int v = y - vec[n - 1];
            forr(i, 1, n)
            {
                vec[i] += v;
            }
            for (auto e : vec)
                printf("%d ", e);
            printf("\n");
        }
    }
}