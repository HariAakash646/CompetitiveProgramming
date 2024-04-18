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

int inf = 1e9 + 1;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);

        bool yes = true;
        mseti st;
        int med;
        frange(i, n)
        {
            int a;
            scd(a);
            if (!yes)
                continue;
            if (st.size())
            {
                if (st.size() == 1)
                {
                    if (a > med)
                    {
                        st.insert(a);
                        st.insert(inf);
                    }
                    else if (a < med)
                    {
                        st.insert(a);
                        st.insert(-inf);
                    }
                    else
                    {
                        // st.insert(a);
                        st.insert(-inf);
                        st.insert(inf);
                    }
                }
                else
                {
                    if (a > med)
                    {
                        auto it = st.upper_bound(med);
                        if (*(it) == a)
                        {
                            st.insert(inf);
                            st.insert(inf);
                        }
                        else if (*(it) > a)
                        {
                            st.insert(inf);
                            st.insert(a);
                        }
                        else
                            yes = false;
                    }
                    else if (a < med)
                    {
                        auto it = st.lower_bound(med);
                        if (*prev(it) == a)
                        {
                            st.insert(-inf);
                            st.insert(-inf);
                        }
                        else if (*prev(it) < a)
                        {
                            st.insert(-inf);
                            st.insert(a);
                        }
                        else
                            yes = false;
                    }
                    else
                    {
                        st.insert(-inf);
                        st.insert(inf);
                        // st.insert(a);
                    }
                }
            }
            else
                st.insert(a);
            med = a;
        }
        if (yes)
            printf("YES\n");
        else
            printf("NO\n");
    }
}