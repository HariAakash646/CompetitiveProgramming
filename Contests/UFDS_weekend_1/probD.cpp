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

vll vec;
int n, l;

lli dist(int a, int b)
{
    if (a > b)
        swap(a, b);
    return min(vec[b] - vec[a], (vec[a] + l) - vec[b]);
}

int main()
{

    scd(n);
    scd(l);

    vec = vll(n + 1);
    vll tim(n + 1);

    forr(i, 1, n + 1) sclld(vec[i]);
    forr(i, 1, n + 1) sclld(tim[i]);

    vector<vector<vector<pair<lli, lli>>>> dp1(n + 1, vector<vector<pair<lli, lli>>>(n + 1, vector<pair<lli, lli>>(n + 1, mp(-1, -1))));
    dp1[0][0][0] = mp(0, 0);
    n++;
    forr(i, 0, n)
    {
        forr(l, 1, n)
        {
            for (int j = 0; j < n; j++)
            {
                int e = (j + l) % n;
                if (i - 1 >= 0 && dp1[(j + 1) % n][e][i - 1].f != -1 && dp1[(j + 1) % n][e][i - 1].f + dist((j + 1) % n, j) <= tim[j])
                    dp1[j][e][i].f = dp1[(j + 1) % n][e][i - 1].f + dist((j + 1) % n, j);
                if (i - 1 >= 0 && dp1[(j + 1) % n][e][i - 1].s != -1 && dp1[(j + 1) % n][e][i - 1].s + dist(e, j) <= tim[j])
                {
                    if (dp1[j][e][i].f == -1)
                    {
                        dp1[j][e][i].f = dp1[(j + 1) % n][e][i - 1].s + dist(e, j);
                    }
                    else
                    {
                        dp1[j][e][i].f = min(dp1[j][e][i].f, dp1[(j + 1) % n][e][i - 1].s + dist(e, j));
                    }
                }
                if (dp1[(j + 1) % n][e][i].f != -1)
                {
                    if (dp1[j][e][i].f == -1)
                    {
                        dp1[j][e][i].f = dp1[(j + 1) % n][e][i].f + dist((j + 1) % n, j);
                    }
                    else
                    {
                        dp1[j][e][i].f = min(dp1[j][e][i].f, dp1[(j + 1) % n][e][i].f + dist((j + 1) % n, j));
                    }
                }
                if (dp1[(j + 1) % n][e][i].s != -1)
                {
                    if (dp1[j][e][i].f == -1)
                    {
                        dp1[j][e][i].f = dp1[(j + 1) % n][e][i].s + dist(e, j);
                    }
                    else
                    {
                        dp1[j][e][i].f = min(dp1[j][e][i].f, dp1[(j + 1) % n][e][i].s + dist(e, j));
                    }
                }

                if (i - 1 >= 0 && dp1[j][(e - 1 + n) % n][i - 1].s != -1 && dp1[j][(e - 1 + n) % n][i - 1].s + dist((e - 1 + n) % n, e) <= tim[e])
                    dp1[j][e][i].s = dp1[j][(e - 1 + n) % n][i - 1].s + dist((e - 1 + n) % n, e);
                if (i - 1 >= 0 && dp1[j][(e - 1 + n) % n][i - 1].f != -1 && dp1[j][(e - 1 + n) % n][i - 1].f + dist(j, e) <= tim[e])
                {
                    if (dp1[j][e][i].s == -1)
                    {
                        dp1[j][e][i].s = dp1[j][(e - 1 + n) % n][i - 1].f + dist(j, e);
                    }
                    else
                    {
                        dp1[j][e][i].s = min(dp1[j][e][i].s, dp1[j][(e - 1 + n) % n][i - 1].f + dist(j, e));
                    }
                }
                if (dp1[j][(e - 1 + n) % n][i].s != -1)
                {
                    if (dp1[j][e][i].s == -1)
                    {
                        dp1[j][e][i].s = dp1[j][(e - 1 + n) % n][i].s + dist((e - 1 + n) % n, e);
                    }
                    else
                    {
                        dp1[j][e][i].s = min(dp1[j][e][i].s, dp1[j][(e - 1 + n) % n][i].s + dist((e - 1 + n) % n, e));
                    }
                }
                if (dp1[j][(e - 1 + n) % n][i].f != -1)
                {
                    if (dp1[j][e][i].s == -1)
                    {
                        dp1[j][e][i].s = dp1[j][(e - 1 + n) % n][i].f + dist(e, j);
                    }
                    else
                    {
                        dp1[j][e][i].s = min(dp1[j][e][i].s, dp1[j][(e - 1 + n) % n][i].f + dist(e, j));
                    }
                }
            }
        }
    }

    int c = 0;
    frange(i, n)
    {
        frange(j, n)
        {
            frange(k, n)
            {
                if (dp1[j][k][i].f != -1 || dp1[j][k][i].s != -1)
                    c = i;
            }
        }
    }
    printf("%d", c);
}