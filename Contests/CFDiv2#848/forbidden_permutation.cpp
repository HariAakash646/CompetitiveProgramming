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
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m, d;
        scd(n);
        scd(m);
        scd(d);
        vi vec(n + 1);
        frange(i, n)
        {
            int a;
            scd(a);
            vec[a] = i + 1;
        }
        vi avec(m);
        frange(i, m)
        {
            scd(avec[i]);
        }
        for (auto e : avec)
        {
            // printf("%d : %d\n", e, vec[e]);
        }
        int sw = 0;
        forr(i, 0, m - 1)
        {
            if ((vec[avec[i + 1]] > vec[avec[i]]) && (vec[avec[i + 1]] <= vec[avec[i]] + d))
            {

                sw += min((d - (vec[avec[i + 1]] - vec[avec[i]]) + 1), vec[avec[i + 1]] - vec[avec[i]]);
            }
        }
        printf("%d\n", sw);
    }
}