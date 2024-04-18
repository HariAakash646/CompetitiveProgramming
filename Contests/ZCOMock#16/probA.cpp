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

vector<vll> rmq, ramq;

lli rmin(int l, int r)
{
    int ml = 31 - __builtin_clz(r - l);
    return min(rmq[ml][l], rmq[ml][l + (1 << ml)]);
}

lli rmax(int l, int r)
{
    int ml = 31 - __builtin_clz(r - l);
    return max(ramq[ml][l], ramq[ml][l + (1 << ml)]);
}

int main()
{
    int n;
    scd(n);
    vi vec(n);
    ramq = rmq = vector<vll>(20, vll(n));
    frange(i, n)
    {
        scd(vec[i]);
    }

    vll pref(n);
    pref[0] = vec[0];

    forr(i, 1, n)
    {
        if (i % 2)
            pref[i] = pref[i - 1] - vec[i];
        else
            pref[i] = pref[i - 1] + vec[i];
    }

    frange(i, n)
    {
        rmq[0][i] = pref[i];
        ramq[0][i] = pref[i];
    }

    forr(i, 1, 20)
    {
        frange(j, n)
        {
            if (j + (1 << i) - 1 < n)
            {
                rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
                ramq[i][j] = max(ramq[i - 1][j], ramq[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    lli c = 0;
    frange(i, n)
    {
    }
}