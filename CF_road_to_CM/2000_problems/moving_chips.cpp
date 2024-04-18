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
        vvi vec(n, vi(2));
        vi val(2);
        frange(j, 2)
        {
            frange(i, n)
            {
                char c;
                cin >> c;
                if (c == '*')
                {
                    vec[i][j] = 1;
                    val[j]++;
                }
            }
        }

        vll pref(n), suf(n);
        vll pcnt(n), scnt(n);

        pref[0] = 0;
        pcnt[0] = vec[0][0] + vec[0][1];
        forr(i, 1, n)
        {
            pref[i] = pref[i - 1] + i * (vec[i][0] + vec[i][1]);
            pcnt[i] = pcnt[i - 1] + vec[i][0] + vec[i][1];
        }

        suf[n - 1] = (n - 1) * (vec[n - 1][0] + vec[n - 1][1]);
        scnt[n - 1] = vec[n - 1][0] + vec[n - 1][1];
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + i * (vec[i][0] + vec[i][1]);
            suf[i] = suf[i + 1] + vec[i][0] + vec[i][1];
        }

        lli mi = 1e18;
        frange(i, n)
        {
            frange(j, 2)
            {
                mi = min(mi, i * pcnt[i] - pref[i] + suf[i] - i * scnt[i] + val[j]);
            }
        }
        printf("%lld\n", mi);
    }
}