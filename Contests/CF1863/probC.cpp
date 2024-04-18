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
        int n, k;
        scd(n);
        scd(k);
        seti st;
        frange(i, n + 1) st.insert(i);

        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
            st.erase(vec[i]);
        }
        vec.pb(*st.begin());
        // frange(i, n)
        // {
        //     int a = vec[i];
        //     vec[i] = *st.begin();
        //     st.erase(st.begin());
        //     st.insert(a);
        //     if (i + 1 == k)
        //     {
        //         k = 0;
        //         break;
        //     }
        // }
        // int cyc = k / n;

        vi ne(n + 1);
        frange(i, n + 1)
        {
            ne[(i + k) % (n + 1)] = vec[i];
        }
        if (k % (n + 1))
        {
            ne[k % (n + 1) - 1] = *st.begin();
        }
        frange(i, n + 1) st.insert(i);
        // k = k % n;
        // for (auto e : ne)
        //     st.erase(e);
        // frange(i, k)
        // {
        //     int a = ne[i];
        //     ne[i] = *st.begin();
        //     st.erase(st.begin());
        //     st.insert(a);
        // }
        frange(i, n) printf("%d ", ne[i]);
        printf("\n");
    }
}