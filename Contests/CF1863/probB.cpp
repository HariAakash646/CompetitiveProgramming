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
        seti st;
        frange(i, n)
        {
            scd(vec[i]);
        }
        int mi = 1e9;

        int c = 0;
        seti rem;
        frange(i, n)
        {
            auto it = st.lower_bound(vec[i]);
            auto it2 = rem.upper_bound(vec[i]);
            if (it != st.end() && (it2 == rem.end() || *it2 > *it))
            {
                // printf("%d ", *it);
                rem.insert(*it);
                st.erase(it);
                c++;
            }

            st.insert(vec[i]);
        }
        printf("%d\n", c);
    }
}