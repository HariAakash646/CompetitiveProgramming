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
typedef vector<vll> vvll;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef pair<int, pii> piii;

lli mod = 4294967296;

vvll matmul(vvll a, vvll b, lli mod)
{
    int r1 = a.size();
    int c1 = a[0].size();
    int r2 = b.size();
    int c2 = b[0].size();
    vvll prod(r1, vll(c2));
    frange(i, r1)
    {
        frange(j, c2)
        {
            frange(k, c1)
            {
                prod[i][j] += (a[i][k] * b[k][j]) % mod;
                prod[i][j] %= mod;
            }
        }
    }
    return prod;
}

vvll matexp(vvll a, lli n, lli mod)
{
    vvll out(a.size(), vll(a.size()));
    frange(i, a.size())
    {
        out[i][i] = 1;
    }
    while (n)
    {
        if (n % 2)
        {
            out = matmul(a, out, mod);
        }
        a = matmul(a, a, mod);
        n /= 2;
    }
    return out;
}

int main()
{
    lli k;
    sclld(k);
    vvll mat(65, vll(65));
    frange(i, 64)
    {
        frange(j, 64)
        {
            int x1 = i / 8;
            int y1 = i % 8;
            int x2 = j / 8;
            int y2 = j % 8;
            if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2))
            {
                mat[i + 1][j + 1] = 1;
            }
        }
    }
    frange(i, 65) mat[0][i] = mat[1][i];
    mat[0][0] = 1;
    // mat[0][1] = 1;
    mat = matexp(mat, k, mod);
    vvll pos(1, vll(65));
    pos[0][0] = 1;
    vvll out = matmul(pos, mat, mod);
    lli tot = 0;
    for (auto e : out[0])
        tot = (tot + e) % mod;
    printf("%lld", tot);
}