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

string bin(int x)
{
    string str = "";
    frange(i, 20)
    {
        str += "0";
    }

    frange(i, 20)
    {
        if (x % 2)
        {
            str[i] = '1';
        }
        x /= 2;
    }
    return str;
}

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    vi cn(20);
    for (auto e : vec)
    {
        string out = bin(e);
        frange(i, 20)
        {
            if (out[i] == '1')
            {
                cn[i]++;
            }
        }
    }
    vi ans(n);
    frange(i, 20)
    {
        frange(j, cn[i])
        {
            ans[j] += 1 << i;
        }
    }
    lli tot = 0;
    for (auto e : ans)
    {
        tot += lli(e) * lli(e);
    }
    printf("%lld", tot);
}