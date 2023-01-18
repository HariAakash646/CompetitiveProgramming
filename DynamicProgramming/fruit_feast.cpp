// Not working
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

int main()
{
    // freopen("feast.in", "r", stdin);
    // freopen("feast.out", "w", stdout);
    int t, a, b;
    scd(t);
    scd(a);
    scd(b);
    vi vec(t + 1, 0);
    vi hec(t + 1, 0);
    vb ht(t + 1, false);
    vec[0] = 1;
    hec[0] = 1;
    if (b > a)
        swap(a, b);
    forr(i, b, t + 1)
    {
        if (i < a)
        {
            vec[i] = vec[i - b];
            ht[i] = ht[i - b];
        }
        else
        {
            if (vec[i - a])
            {
                vec[i] = vec[i - a];
                ht[i] = ht[i - a];
            }
            else
            {
                vec[i] = vec[i - b];
                ht[i] = ht[i - b];
            }
            if (vec[i - a] && vec[i - a])
            {
                ht[i] = ht[i - a] && ht[i - b];
            }
        }
        if (!vec[i / 2] && vec[i])
        {
            hec[i / 2] = 1;
        }
        if (!vec[i] && !ht[i - a] && hec[i - a])
        {
            vec[i] = 1;
            ht[i] = true;
        }
        if (!vec[i] && !ht[i - b] && hec[i - b])
        {
            vec[i] = 1;
            ht[i] = true;
        }
    }
    int m = 0;
    frange(i, t + 1)
    {
        if (vec[i])
            m = i;
    }
    printf("%d", m);
}