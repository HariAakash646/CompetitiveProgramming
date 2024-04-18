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
    // scd(t);
    t = 100000;
    frange(_, t)
    {
        int n;
        lli k;
        // scd(n);
        // sclld(k);
        n = rand() % 10;
        k = rand() % 10;
        vector<pair<lli, lli>> vec(n);
        // frange(i, n)
        // {
        //     sclld(vec[i].f);
        // }
        // frange(i, n)
        // {
        //     sclld(vec[i].s);
        // }
        int pre = -2;
        frange(i, n)
        {
            vec[i].f = rand() % 10 + pre + 2;
            vec[i].s = rand() % 10 + vec[i].f;
            pre = vec[i].s;
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
            // printf("-1\n");
            continue;
        }
        lli en = vec[i].f + (k - tot) - 1;
        ans += 2;
        tot = k;
        // while (cnt && en <= vec[i].s)
        // {
        //     cnt--;
        //     en++;
        //     ans -= 1;
        // }
        int c = 0;
        lli la_en = en;
        lli ans2 = ans;

        lli en2 = en + 1;
        ans += en;
        lli ans3 = ans;
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
        while (cnt && en2 <= vec[i].s)
        {
            cnt--;
            en2++;
            ans3 -= 1;
        }
        if (ans3 != min(ans, ans2))
        {
            // if (ans3 > 15)
            //     continue;
            printf("%lld %lld\n", ans3, min(ans, ans2));
            printf("%d %lld\n", n, k);
            for (auto p : vec)
            {
                printf("%lld %lld\n", p.f, p.s);
            }
            return 0;
        }
    }
}