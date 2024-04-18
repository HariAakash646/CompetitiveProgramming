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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi v1;
        forr(i, 1, (1 << n) + 1)
        {
            v1.pb(i);
        }

        while (v1.size() > 1)
        {
            vi v2;
            auto it1 = v1.begin();
            auto it2 = prev(v1.end());
            while (it1 < it2)
            {
                cout << "? " << *it1 << " " << *it2 << endl;
                int a;
                cin >> a;
                if (a == 1)
                {
                    v2.pb(*it1);
                    if (*it1 != *prev(it2))
                        v2.pb(*prev(it2));
                }
                else if (a == 2)
                {
                    v2.pb(*it2);
                    if (*next(it1) != *it2)
                        v2.pb(*next(it1));
                }
                else if (a == 0)
                {
                    v2.pb(*prev(it2));
                    if (*next(it1) != *prev(it2))
                        v2.pb(*next(it1));
                }
                if (a == -1)
                {
                    return 0;
                }

                it1 += 2;
                it2 -= 2;
            }
            v1 = v2;
            sort(all(v1));
        }
        cout << "! " << v1[0] << endl;
    }
}