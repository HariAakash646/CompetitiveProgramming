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

int inf = 1e8;

struct Elem
{
    int lt = 0;
    int rt = 0;
    int lf = 0;
    int rf = 0;
};

int main()
{
    string str;
    int k;
    cin >> str >> k;

    int n = str.size();
    Elem e;
    e.lt = -inf;
    e.rt = -inf;
    e.lf = -inf;
    e.rf = -inf;
    vector<vector<Elem>> dp1(n, vector<Elem>(k + 1, e));
    e.lt = inf;
    e.rt = inf;
    e.lf = inf;
    e.rf = inf;
    vector<vector<Elem>> dp2(n, vector<Elem>(k + 1, e));

    if (str[0] == 'T')
    {
        dp1[0][0].lt = 0;
    }
}