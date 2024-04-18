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
        lli num = 1;
        lli den = 1;
        long double ma = 0.0;
        int len = 0;
        int malen = 0;
        vi out(n);
        forr(k, 1, n + 1)
        {
            num *= lli(vec[k - 1]);
            // cout << num << "\n";
            if (vec[k - 1 - len] >= len + 1)
            {
                len++;
                den *= len;
            }
            else
            {
                num /= vec[k - 1 - len];
            }
            if (num < den - 1e-8)
            {
                num = 1;
                den = 1;
                len = 0;
            }

            if (double(num) / double(den) > ma)
            {

                malen = len;
            }
            if (double(num) / double(den) == ma)
            {
                malen = max(malen, len);
            }
            out[k - 1] = malen;
        }
        for (auto e : out)
        {
            printf("%d ", e);
        }
        printf("\n");
    }
}