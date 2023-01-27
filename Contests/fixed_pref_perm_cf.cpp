#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vector<string> nums(n);
        vector<set<pii>> numset(n);
        vector<string> numsi(n);
        frange(i, n)
        {
            string num;
            frange(j, m)
            {
                int a;
                scd(a);
                num += to_string(a - 1);
                numset[i].insert({a - 1, j});
            }
            nums[i] = num;
            num = "";
            for (auto e : numset[i])
            {
                num += to_string(e.s);
            }
            numsi[i] = num;
            // printf("%lld %lld\n", nums[i], numsi[i]);
        }
        // printf("\n");
        sort(all(numsi));
        for (auto e : nums)
        {
            auto itr = lower_bound(all(numsi), e);
            // int a = m - to_string(abs(*itr - e)).size();
            int a = 0;
            if (itr != numsi.end())
            {
                string a1 = *itr;
                string a2 = e;
                a = 0;
                frange(i, m)
                {
                    if (a1[i] == a2[i])
                        a++;
                    else
                        break;
                }
            }

            // if (abs(*itr - e) == 0)
            //     a = m;
            int b = 0;
            if (itr != numsi.begin())
            {
                // b = m - to_string(abs(*prev(itr) - e)).size();
                string a1 = *prev(itr);
                string a2 = e;
                frange(i, m)
                {
                    if (a1[i] == a2[i])
                        b++;
                    else
                        break;
                }
            }
            printf("%d ", max(a, b));
        }
        printf("\n");
    }
}