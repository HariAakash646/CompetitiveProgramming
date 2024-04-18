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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vi disset;
vi sze;

int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
}

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n, p;
        scd(n);
        scd(p);
        vi vec(n + 1);
        vii val;
        forr(i, 1, n + 1)
        {
            scd(vec[i]);
            val.pb(mp(vec[i], i));
        }
        sort(all(val));
        vi cnt(n + 1);
        lli tot = 0;

        sze = vi(n + 1, 1);
        disset = vi(n + 1);

        forr(i, 1, n + 1) disset[i] = i;

        for (auto e : val)
        {
            if (e.f > p)
                break;
            if (cnt[e.s])
                break;
            int curr = e.f;
            forr(i, e.s + 1, n + 1)
            {
                curr = gcd(vec[i], curr);
                if (vec[i] >= e.f && curr == e.f)
                {

                    if (findf(i) == findf(e.s))
                        break;
                    cnt[e.s]++;
                    tot += e.f;
                    unionf(i, e.s);
                }
                else
                    break;
            }
            curr = e.f;
            for (int i = e.s - 1; i >= 1; i--)
            {
                curr = gcd(vec[i], curr);
                if (vec[i] >= e.f && curr == e.f)
                {

                    if (findf(i) == findf(e.s))
                        break;
                    cnt[e.s]++;
                    tot += e.f;
                    unionf(i, e.s);
                }
                else
                    break;
            }
        }

        forr(i, 1, n + 1)
        {
            if (i < n && findf(i) != findf(i + 1))
            {
                unionf(i, i + 1);
                tot += p;
            }

            if (i > 1 && findf(i) != findf(i - 1))
            {
                unionf(i, i - 1);
                tot += p;
            }
        }
        printf("%lld\n", tot);
    }
}