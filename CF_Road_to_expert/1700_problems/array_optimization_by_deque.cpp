#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        deque<int> dq;
        ordered_set st;
        ordered_set stneg;
        lli tot = 0;
        for (auto e : vec)
        {
            int l = st.order_of_key(e);
            int h = stneg.order_of_key(-e);
            st.insert(e);
            stneg.insert(-e);
            if (l < h)
            {
                dq.push_front(e);
                tot += l;
            }
            else
            {
                dq.push_back(e);
                tot += h;
            }
        }

        // while (dq.size())
        // {
        //     printf("%d ", dq.front());
        //     dq.pop_front();
        // }
        // printf("\n");
        printf("%lld\n", tot);
    }
}