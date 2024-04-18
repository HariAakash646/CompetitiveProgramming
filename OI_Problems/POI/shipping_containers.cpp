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
    int n, q;
    scd(n);
    scd(q);
    int x = sqrt(n);

    vector<vi> vec(n + 1, vi(x + 1));
    vi cnt(n + 1);
    frange(i, q)
    {
        int a, l, d;
        scd(a);
        scd(l);
        scd(d);
        if (d <= x)
        {
            vec[a][d]++;
            if (a + l * d <= n)
                vec[a + (l)*d][d]--;
        }
        else
        {
            frange(i, l)
            {
                cnt[a]++;
                a += d;
            }
        }
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, x + 1)
        {
            cnt[i] += vec[i][j];
            if (i + j <= n)
                vec[i + j][j] += vec[i][j];
        }
        // vec[i] = {};
        // vec[i].shrink_to_fit();

        printf("%d ", cnt[i]);
    }
}