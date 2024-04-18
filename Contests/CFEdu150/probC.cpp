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

int inf = 2e9;

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        string str;
        cin >> str;
        int n = str.size();
        vector<vvi> dp1(n + 1, vvi(5, vi(5, (-inf))));
        vector<vvi> dp2(n + 1, vvi(5, vi(5, (-inf))));
        // vector<vvi> mdp1(n+1, vvi(5, vi(5, (-inf))));
        // vector<vvi> mdp2(n+1, vvi(5, vi(5, (-inf))));
        vi val(5);
        val[0] = 1;
        val[1] = 10;
        val[2] = 100;
        val[3] = 1000;
        val[4] = 10000;
        dp1[n - 1][str[n - 1] - 'A'][str[n - 1] - 'A'] = val[str[n - 1] - 'A'];
        frange(i, 5)
        {
            dp2[n - 1][i][i] = val[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            frange(j, 5)
            {
                forr(k, j, 5)
                {
                    if (j == str[i] - 'A')
                    {
                        if (j == k)
                        {
                            frange(l, k + 1)
                            {
                                dp1[i][j][k] = max(dp1[i][j][k], dp1[i + 1][str[i + 1] - 'A'][l] + val[j]);
                            }
                        }
                        else
                            dp1[i][j][k] = dp1[i + 1][str[i + 1] - 'A'][k] - val[j];
                    }
                }
            }
            frange(j, 5)
            {
                forr(k, j, 5)
                {
                    if (j == str[i] - 'A')
                    {
                        if (j == k)
                        {
                            frange(l, k + 1)
                            {
                                frange(p, l + 1)
                                {
                                    dp2[i][j][k] = max(dp2[i][j][k], dp2[i + 1][p][l] + val[j]);
                                }
                            }
                        }
                        else
                        {
                            frange(p, k + 1)
                                dp2[i][j][k] = max(dp2[i][j][k], dp2[i + 1][p][k] - val[j]);
                        }
                    }
                    else
                    {
                        if (j == k)
                        {
                            frange(l, k + 1)
                            {
                                dp2[i][j][k] = max(dp2[i][j][k], dp1[i + 1][str[i + 1] - 'A'][l] + val[j]);
                            }
                        }
                        else
                            dp2[i][j][k] = dp1[i + 1][str[i + 1] - 'A'][k] - val[j];
                    }
                }
            }
        }
        int ma = -inf;
        frange(j, 5)
        {
            forr(k, j, 5)
            {
                ma = max(ma, dp1[0][j][k]);
                ma = max(ma, dp2[0][j][k]);
            }
        }
        printf("%d\n", ma);
    }
}