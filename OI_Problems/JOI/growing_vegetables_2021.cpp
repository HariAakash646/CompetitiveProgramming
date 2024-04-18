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
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    vll ord(n), rev(n);
    int curr = vec[0] + 1;
    forr(i, 1, n)
    {
        ord[i] = ord[i - 1] + max(0, vec[i - 1] - vec[i] + 1);
        curr = max(vec[i], curr) + 1;
    }
    curr = vec[n - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
    {
        rev[i] = rev[i + 1] + max(0, vec[i + 1] - vec[i] + 1);
        curr = max(vec[i], curr) + 1;
    }
    lli mi = 1e18;
    frange(i, n)
    {
        mi = min(mi, max(ord[i], rev[i]));
    }
    printf("%lld", mi);
}