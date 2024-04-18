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

vector<vi> memo;
vi vec;

int n, d;

int rec(int x, int l)
{
    if (l <= 0)
        return 0;
    if (x > 30000)
        return 0;
    if (memo[x][l - (d - 246)] != -1)
        return memo[x][l - (d - 246)];
    memo[x][l - (d - 246)] = vec[x] + max({rec(x + l, l), rec(x + l + 1, l + 1), rec(x + l - 1, l - 1)});
    return memo[x][l - (d - 246)];
}

int main()
{

    scd(n);
    scd(d);
    vec = vi(30000 + 1);
    memo = vector<vi>(30000 + 1, vi(500, -1));

    forr(i, 1, n + 1)
    {
        int a;
        scd(a);
        vec[a]++;
    }
    int v = rec(d, d);

    printf("%d", v);
}