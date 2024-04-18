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
        int n, s1;
        scd(n);
        scd(s1);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        int i1 = 0;
        int i2 = 0;
        int st = -1;
        int en = -2;
        lli tot = s1 + vec[0];
        while (i2 != n)
        {

            if (tot < 0)
            {
                tot -= vec[i1];
                i1++;
                if (i2 < i1)
                {
                    i2 = i1;
                    tot += vec[i2];
                }
            }
            else
            {
                if (i2 - i1 + 1 >= en - st + 1)
                {
                    st = i1;
                    en = i2;
                }
                i2++;
                tot += vec[i2];
            }
        }
        if (st < 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n", st + 1, en + 1);
        }
    }
}