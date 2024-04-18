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
typedef pair<int, pii> piii;

lli n;
lli mod = 998244353;

lli modinv(lli i)
{
    return i <= 1 ? i : mod - (mod / i) * modinv(mod % i) % mod;
}

map<lli, lli> mem;

lli dp(lli x)
{
    if (x > n)
        return 0;
    if (x == n)
        return 1;
    if (mem.find(x) != mem.end())
        return mem[x];
    mem[x] = (((dp(2 * x) + dp(3 * x) + dp(4 * x) + dp(5 * x) + dp(6 * x)) % mod) * modinv(5)) % mod;
    return mem[x];
}

int main()
{

    sclld(n);
    printf("%lld", dp(1));
}