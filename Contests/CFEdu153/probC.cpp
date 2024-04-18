#include <bits/stdc++.h>

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

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);

        seti st;
        frange(i, n) st.insert(i + 1);

        vb dp(n + 1);
        int mi = 1e9;
        for (auto e : vec)
        {
            if (st.find(e) != st.end())
                st.erase(e);
            if (e < mi)
            {
                mi = e;
                dp[e] = true;
            }
            if (!dp[e])
            {
                auto it = st.upper_bound(e);
                while (it != st.end())
                {
                    dp[*it] = true;
                    it++;
                    st.erase(prev(it));
                }
            }
        }
        int c = 0;
        forr(i, 1, n + 1)
        {
            if (!dp[i])
                c++;
        }
        printf("%d\n", c);
    }
}