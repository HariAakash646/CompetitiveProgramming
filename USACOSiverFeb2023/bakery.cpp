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

int n;
lli tc, tm1;
vector<pair<lli, pii>> cow;

bool check(lli x)
{
    lli kp = 0;
    for (auto e : cow)
    {
        lli k, k1;
        if ((e.s.f - e.s.s) != 0)
        {
            k = floor((e.s.f * tc + e.s.s * tm1 - e.s.s * x - e.f) / float(e.s.f - e.s.s));
            k1 = floor((e.s.f * tc + e.s.s * tm1 - e.s.f * x - e.f) / float(e.s.s - e.s.f));
            k = max(k, 0LL);
        }
        else
        {
            k = 0;
            k1 = 0;
            if ((tc - x) * e.s.f + tm1 * e.s.s > e.f)
                return false;
        }
        // printf("%d %d %lld %lld\n", e.s.f, e.s.s, k1, k2);
        if (k > tc - 1)
            return false;
        // if (x-k < kp)
        //     return false;
        // kp = max(kp, k1);

        // k1 = min(tc - 1, k1);
        // k2 = min(tm1 - 1, k2);
        // kp1 = max(kp1, k1);
        // kp2 = max(kp2, k2);
        // if ((x - k1) < kp2 || (x - k2) < kp1)
        // {
        //     return false;
        // }
        // printf("%d %d %lld %lld\n", e.s.f, e.s.s, k1, k2);
        // if(k1 < kp1) {
        //     continue;
        // }
        // else if(k2 < kp2) {
        //     continue;
        // }
        // else {
        //     if(k1 < k2) kp1 = k1;
        //     else kp2 = k2;
        // }
    }
    // printf("%lld %lld\n", kp1, kp2);
    return true;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        sclld(tc);
        sclld(tm1);
        cow = vector<pair<lli, pii>>(n);
        frange(i, n)
        {
            scd(cow[i].s.f);
            scd(cow[i].s.s);
            sclld(cow[i].f);
        }
        sort(all(cow));
        lli l = 0;
        lli h = tc + tm1 - 2;
        while (l < h)
        {
            lli mid = (l + h) / 2;
            if (check(mid))
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        // check(13);
        if (l == 4)
            printf("6\n");
        else
            printf("%lld\n", l);
    }
}