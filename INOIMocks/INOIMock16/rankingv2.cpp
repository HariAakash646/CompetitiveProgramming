#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vector<vector<lli>> ans;
lli a = 0;
lli b = 0;
lli cv = 0;
int check(lli v)
{
    lli c = (cv - v);
    if (((b * b) - (4 * a * c)) >= 0)
        return true;
    else
        return false;
}

int main()
{

    frange(i, 50)
    {
        lli n, m, k;
        // sclld(n);
        // sclld(m);
        // sclld(k);
        n = rand() % 100 + 1;
        m = rand() % 100 + 1;
        k = rand() % 100 + 1;
        ans = vector<vector<lli>>(m, vector<lli>(n));
        frange(i, n)
        {
            frange(j, m)
            {
                ans[j][i] = rand() % 100 + 1;
            }
        }
        a = n;
        lli tot = 0;
        {
            frange(i, m)
            {
                b = 0;
                cv = 0;
                frange(j, n)
                {
                    b = (b + 2 * ans[i][j]);
                    cv = (cv + (ans[i][j] * ans[i][j]));
                }
                lli l = 0;
                lli h = 1e14;
                while (l != h)
                {
                    lli mid = (l + h) / 2;
                    if (check(mid))
                    {
                        h = mid;
                    }
                    else
                        l = mid + 1;
                }
                // lli k1 = 0;
                // frange(_, h + 1)
                // {

                //     if (check(k1))
                //         break;
                //     k1++;
                // }
                tot += l;
            }
        }
        lli tot1 = tot;
        {
            frange(i, m)
            {
                b = 0;
                cv = 0;
                lli mi = 1e18;

                forr(k1, 1, k + 1)
                {
                    lli t = 0;
                    frange(j, n)
                    {
                        t += (ans[i][j] - k1) * (ans[i][j] - k1);
                    }
                    mi = min(mi, t);
                }
                tot += mi;
            }
        }
        if (tot1 != tot)
        {
            printf("%d %d %d\n", n, m, k);
            frange(i, m)
            {
                frange(j, n)
                {
                    printf("%d ", ans[i][j]);
                }
                printf("\n");
            }
            printf("%d %d\n", tot1, tot);
        }
    }
}