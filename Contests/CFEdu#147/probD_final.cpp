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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        lli k;
        scd(n);
        sclld(k);
        vector<pair<lli, lli>> vec(n);
        frange(i, n)
        {
            sclld(vec[i].f);
        }
        frange(i, n)
        {
            sclld(vec[i].s);
        }
        lli tot = 0;
        int i;
        int cnt = 0;
        lli ans = 0;
        bool done = false;
        for (i = 0; i < n; i++)
        {
            tot += vec[i].s - vec[i].f + 1;
            if (vec[i].s == vec[i].f)
                cnt++;
            if (tot >= k)
            {
                tot -= vec[i].s - vec[i].f + 1;
                if (vec[i].s == vec[i].f)
                    cnt--;
                done = true;
                break;
            }
            ans += 2;
        }
        if (!done)
        {
            printf("-1\n");
            continue;
        }
        lli en = vec[i].f + (k - tot) - 1;
        ans += 2;
        tot = k;

        int c = 0;
        lli la_en = en;
        lli ans2 = ans;

        ans += en;
        frange(i, 2 * cnt)
        {
            en++;
            auto it = upper_bound(all(vec), mp(en, 0LL));
            it--;
            if ((*it).s >= en)
            {
                c++;
                ans2 -= 2;
                la_en = en;
                if (en == (*it).f)
                    ans2 += 2;
                if (c >= cnt)
                    break;
            }
        }
        ans2 += la_en;

        printf("%lld\n", min(ans, ans2));
    }
}