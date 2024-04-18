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
    int n;
    scd(n);
    vi vec(n + 1);

    forr(i, 1, n + 1) scd(vec[i]);
    vi cnt(n);
    int ma = 0;
    forr(i, 1, n + 1)
    {
        ma = max(ma, vec[i]);
        cnt[vec[i]]++;
    }
    if (cnt[1] >= 3 || (cnt[1] >= 2 && n > 2))
    {
        printf("Impossible");
        return 0;
    }
    bool done = true;
    frange(i, (ma + 1) / 2)
    {
        if (cnt[ma - i] < 2)
            done = false;
    }
    if (ma % 2 == 0)
    {
        if (cnt[ma / 2] != 1)
            done = false;
    }
    frange(i, (ma + 1) / 2)
    {
        if (cnt[i])
            done = false;
    }
    if (ma % 2)
    {
        if (cnt[(ma + 1) / 2] != 2)
            done = false;
    }
    if (done)
        printf("Possible");
    else
        printf("Impossible");
}