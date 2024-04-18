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
        int n, m;
        scd(n);
        scd(m);
        vi vec(n + 1);
        vec[0] = 1e9 + 10;
        forr(i, 1, n + 1) scd(vec[i]);

        seti st;
        int mv = 1e9 + 10;
        st.insert(0);
        forr(i, 1, n + 1)
        {
            if (vec[i] < mv)
            {
                st.insert(i);
                mv = vec[i];
            }
        }

        frange(i, m)
        {
            int k, x;
            scd(k);
            scd(x);
            auto it = st.upper_bound(k);
            if (it == st.begin())
            {
                printf("Prob: %d\n", k);
                continue;
            }
            it--;

            vec[k] -= x;
            if (vec[*it] > vec[k])
                st.insert(k);
            it = st.upper_bound(k);
            vi er;

            for (; it != st.end(); it++)
            {
                if (vec[*it] >= vec[k])
                    er.pb(*it);
                else
                    break;
            }

            for (auto e : er)
                st.erase(e);

            printf("%d ", st.size() - 1);
        }
        printf("\n");
    }
}