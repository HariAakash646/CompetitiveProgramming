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
 
const lli mod = 1e9 + 7;
 
vvll matmul(vvll a, vvll b)
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
 
vvll matexp(vvll a, lli n)
{
 
    vvll out(a.size(), vll(a.size()));
    frange(i, a.size())
    {
        out[i][i] = 1;
    }
    if(n == 0) return out;
    out = matexp(a, n/2);
 
    out = matmul(out, out);
 
    if(n % 2) out = matmul(out, a);
 
    return out;
}
 
int main()
{
    int n;
    lli k;
    scd(n);
    sclld(k);
    vvll matrix(n, vll(n));
    frange(i, n) {
      frange(j, n) sclld(matrix[i][j]);
    }
    matrix = matexp(matrix, k);
    lli tot = 0;
    frange(i, n) {
      frange(j, n) {
        tot += matrix[i][j];
        tot %= mod;
      }
    }
    printf("%lld", tot);
}