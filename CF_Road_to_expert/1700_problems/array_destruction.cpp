// Weird Behavious.
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

vii ans;

bool rec(mseti::iterator it, int x, mseti &st)
{
    int a = *it;
    if (st.size() == 0)
        return true;
    if (st.size() == 1)
        return false;
    if (st.size() == 2)
    {
        if (*st.begin() + *prev(st.end()) == x)
        {
            ans.pb({*st.begin(), *prev(st.end())});
            return true;
        }
        else
        {
            return false;
        }
    }
    st.erase(it);
    for (auto e : st)
    {
        if (e + a == x)
        {
            st.erase(st.find(e));
            bool out = rec(prev(st.end()), a, st);
            st.insert(e);
            if (out)
            {
                ans.pb({e, a});
                return true;
            }
        }
    }
    st.insert(a);
    return false;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        mseti vec;
        frange(i, 2 * n)
        {
            int a;
            scd(a);
            vec.insert(a);
        }
        int x = *prev(vec.end());
        vec.erase(prev(vec.end()));
        mseti tmp = vec;
        bool done = false;
        for (auto e : vec)
        {
            ans = {};
            tmp.erase(tmp.find(e));
            bool out = rec(prev(tmp.end()), x, tmp);
            tmp.insert(e);
            if (out)
            {
                printf("YES\n");
                printf("%d\n", x + e);
                reverse(all(ans));
                printf("%d %d\n", e, x);
                for (auto p : ans)
                {
                    printf("%d %d\n", p.f, p.s);
                }
                done = true;
                break;
            }
        }
        if (!done)
            printf("NO\n");
    }
}