#include "ancient2.h"
#include <bits/stdc++.h>
//

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

string Solve(int n)
{
    string out = "";
    frange(i, n / 2 + 1)
    {
        int m = i + 1 + 2;
        vi v1(m), v2(m);
        frange(j, i)
        {
            v1[j] = v2[j] = j + 1;
        }
        v1[i] = i + 1;
        v2[i] = i + 2;
        v2[i + 1] = v1[i + 1] = i + 1;
        v2[i + 2] = v1[i + 2] = i + 2;
        int v = Query(m, v1, v2);
        // for (auto e : v1)
        //     printf("%d ", e);
        // printf("\n");
        // for (auto e : v2)
        //     printf("%d ", e);
        // printf("\n\n");
        if (v == i + 1)
            out += "0";
        else
            out += "1";
    }
    forr(i, n / 2 + 1, n)
    {
        int m = n / 2 + 2;
        // printf("%d %d\n", i, m);
        vi v1(m), v2(m);
        frange(j, m - 1)
        {
            v1[j] = v2[j] = j + 1;
        }
        v1[m - 1] = v2[m - 1] = m - 1;
        v1[m - 2] = v2[m - 2] = 0;
        if (i < m)
        {
            v1[m - 2] = m - 1;
            int v = Query(m, v1, v2);
            if (v == m - 1)
                out += "0";
            else
                out += "1";
        }
        else
        {
            if (out[i - m] == '1')
            {
                v1[i - m] = m - 1;
                if (v == m - 1)
                    out += "0";
                else
                    out += "1";
            }
            else
            {
                v2[i - m] = m - 1;
                if (v == m - 1)
                    out += "1";
                else
                    out += "0";
            }
        }
        // for (auto e : v1)
        //     printf("%d ", e);
        // printf("\n");
        // for (auto e : v2)
        //     printf("%d ", e);
        // printf("\n\n");
        //
        if (v == m - 1)
            out += "1";
        else
            out += "0";
    }
    return out;
}

int main()
{
    Solve(3);
}