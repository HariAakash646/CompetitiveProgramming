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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n;
vector<ld> v1, v2;

bool check(ld x)
{
    ld a = 0;
    ld b = 0;
    int i1 = 0;
    int i2 = 0;
    while (a < x || b < x)
    {
        if (a < x)
        {
            if (i1 >= n)
                return false;
            a += v1[i1] - 1;
            b--;
            i1++;
        }
        if (b < x)
        {
            if (i2 >= n)
                return false;
            b += v2[i2] - 1;
            a--;
            i2++;
        }
    }
    return true;
}

int main()
{

    cin >> n;
    v1 = v2 = vector<ld>(n);
    frange(i, n)
    {
        cin >> v1[i] >> v2[i];
    }
    sort(all(v1), greater<>());
    sort(all(v2), greater<>());

    ld lo = 0;
    ld hi = 1e8;

    while (abs(hi - lo) >= 1e-5)
    {
        ld mid = (lo + hi) / 2;
        if (check(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1e-5;
        }
    }
    cout << fixed << setprecision(4) << lo;
}