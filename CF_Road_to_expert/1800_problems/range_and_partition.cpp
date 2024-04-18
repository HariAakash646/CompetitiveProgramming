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

void usaco()
{
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        vi vec(n + 1);
        vi cnt(n + 1);
        frange(i, n)
        {
            scd(vec[i + 1]);
            cnt[vec[i + 1]]++;
        }
        int tot = n;
        pii range = {1, n};
        pii ans = range;
        while (range.s <= n && range.f >= 1 && range.f <= range.s)
        {
            if (tot < k)
            {
                tot -= 2 * cnt[range.s];
                range.s--;
                range.f--;
                tot += 2 * cnt[range.f];
            }
            else if (tot >= k)
            {
                ans = range;
                tot -= 2 * cnt[range.f];
                range.f++;
            }
        }
        printf("%d %d\n", ans.f, ans.s);
        vi pref(n + 1);
        forr(i, 1, n + 1)
        {
            int v;
            if ((ans.f <= vec[i] && vec[i] <= ans.s))
                v = 1;
            else
                v = -1;
            pref[i] = pref[i - 1] + v;
        }
        int curr = 1;
        int id = 1;
        forr(i, 1, n + 1)
        {
            if (curr == k)
                break;
            if (pref[i] == curr)
            {
                curr++;
                // forr(j, id, i + 1)
                // {
                //     printf("%d ", vec[j]);
                // }
                printf("%d %d\n", id, i);
                id = i + 1;
            }
        }
        // forr(i, id, n + 1)
        // {
        //     printf("%d ", vec[i]);
        // }
        printf("%d %d\n", id, n);
    }
}