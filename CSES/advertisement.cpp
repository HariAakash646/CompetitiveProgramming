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
    int n;
    scd(n);
    vll vec(n);
    frange(i, n)
        sclld(vec[i]);
    stack<pair<lli, int>> stk, stk2;

    lli ma = 0;
    vll vecl(n), vecr(n);
    frange(i, n)
    {
        int l = 0;

        while (stk.size() && stk.top().f >= vec[i])
        {
            l = stk.top().s;
            stk.pop();
        }
        if (stk.size())
            l = stk.top().s;
        else
            l = -1;
        vecl[i] = l;
        stk.push({vec[i], i});
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int r = n - 1;

        while (stk2.size() && stk2.top().f >= vec[i])
        {
            r = stk2.top().s;
            stk2.pop();
        }
        if (stk2.size())
            r = stk2.top().s;
        else
            r = n;
        vecr[i] = r;
        stk2.push({vec[i], i});
    }
    frange(i, n)
    {
        ma = max(ma, vec[i] * (vecr[i] - vecl[i] - 1));
    }
    printf("%lld", ma);
}