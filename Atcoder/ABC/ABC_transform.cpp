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

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    int q;
    cin >> q;
    lli x = 1;
    lli c = 0;
    while (x < 1e18)
    {
        x *= 2;
        c++;
    }
    char fi = str[0];
    map<char, string> m;
    m['A'] = "BC";
    m['B'] = "CA";
    m['C'] = "AB";
    frange(_, q)
    {
        lli t, k;
        cin >> t >> k;

        if (t > c)
        {
            frange(i, (((fi - 65) + t - c) % 3) + 1)
            {
                str = m[str[0]];
            }
            t = c;
        }
        while (t > 0 && k > 1)
        {
            x = 1 << t;
            if (k > x)
            {
                k -= x;
                str = m[str[1]]
            }
            t--;
        }
    }
}