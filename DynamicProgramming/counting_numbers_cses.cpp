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

int dp[18][10][2][2];

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int n = n1.size();
    vi v1(n), v2(n);
    frange(i, n)
    {
        v1[i] = n1[i] - '0';
    }
    frange(i, n - n2.size()) v2[i] = 0;
    forr(i, n - n2.size(), n) v2[i] = n2[i - (n - n2.size())] - '0';
    frange(i, n)
    {
        frange(j, 10)
        {
            frange(k, 2)
            {
                frange(l, 2)
                {
                }
            }
        }
    }
}