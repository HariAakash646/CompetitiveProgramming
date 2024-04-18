// cycle finding not working
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

vi perm;
lli c = 0;
string str;
void dfs(int x, int v)
{
    c++;
    if (str[x] == str[v])
        return;

    dfs(perm[x], v);
}

lli gcd(lli a, lli b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;

        cin >> str;
        perm = vi(n);
        frange(i, n)
        {
            int a;
            scd(a);
            perm[i] = a - 1;
        }
        vll vec(n);
        frange(i, n)
        {
            c = 0;
            dfs(perm[i], i);
            vec[i] = c;
            // printf("%d ", c);
        }
        lli curr = vec[0];
        forr(i, 1, n)
        {
            curr = (curr * vec[i]) / gcd(curr, vec[i]);
        }
        printf("%lld\n", curr);
    }
}