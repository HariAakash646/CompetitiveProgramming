// Not working TLE prev version. WA curr version
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

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    priority_queue<pii> st;
    frange(i, n)
    {
        int a;
        scd(a);
        st.push(mp(-vec[i], a));
    }
    lli tot = 0;
    mseti st1;
    int curr = st.top().f;
    while (st.size())
    {
        auto e = st.top();
        st.pop();
        if (e.f == curr)
        {
            st1.insert(e.s);
        }
        else
        {
            int k = st1.size() - 1;
            for (auto p : st1)
            {
                if (k == 0)
                    break;
                tot += p * k;
                st.push({curr - k, p});
                k--;
            }
            curr = e.f;
            st1 = {e.s};
        }
    }
    int k = st1.size() - 1;
    for (auto p : st1)
    {
        if (k == 0)
            break;
        tot += p * k;
        st.push({-curr, p});
        k--;
    }
    printf("%lld", tot);
}