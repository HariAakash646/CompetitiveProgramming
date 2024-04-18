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
        frange(i, n) scd(vec[i]);
        lli tot = 0;
        vi cnt(n);
        frange(i, n)
        {
            while (cnt[i])
            {
                int tmp = i + vec[i];
                vec[i] = max(vec[i] - 1, 1);
                if (tmp < n)
                    cnt[tmp]++;
                cnt[i]--;
            }
            if (vec[i] > (n - i))
            {
                tot += vec[i] - (n - i);
                vec[i] = (n - i);
            }
            while (vec[i] > 1)
            {
                tot++;
                int tmp = i + vec[i];
                vec[i] = max(vec[i] - 1, 1);
                if (tmp < n)
                    cnt[tmp]++;
            }
        }
        printf("%lld\n", tot);
    }
}