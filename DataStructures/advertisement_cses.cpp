// Incorrect. The queue causes bugs.
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
    queue<pii> q;
    vii vec;
    frange(i, n)
    {
        int a;
        scd(a);
        vec.pb({a, i + 1});
        q.push({a, i + 1});
    }
    stack<pii> stk;
    int ma = 0;
    for (auto e : vec)
    {
        int pr1 = e.s - 1;
        while (stk.size())
        {
            auto p = stk.top();
            pr1 = p.s;
            if (p.f < e.f)
            {
                break;
            }

            stk.pop();
        }
        if (stk.empty())
            pr1 = 0;
        stk.push(e);
        int pr2 = e.s + 1;
        while (q.size())
        {
            auto p = q.front();
            pr2 = p.s;
            if (p.f < e.f)
            {
                break;
            }
            q.pop();
        }
        if (q.empty())
            pr2 = n;
        printf("%d %d %d %d %d\n", e.f, e.s, pr1, pr2, (pr2 - pr1 - 1) * e.f);
        ma = max(ma, (pr2 - pr1 - 1) * e.f);
    }
    printf("%d", ma);
}