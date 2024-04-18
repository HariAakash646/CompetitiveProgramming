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
    int n;
    scd(n);
    vi vec(n);
    vi zer;
    vi one;
    vi two;
    frange(i, n)
    {
        int a;
        scd(a);
        if (a % 3 == 2)
            two.pb(i);
        else if (a % 3 == 1)
            one.pb(i);
        else
            zer.pb(i);
    }
    if (zer.size() <= n / 2)
    {
        printf("0\n");
        string out = "";
        frange(i, n) out += "0";
        int bl = 0;
        for (auto id : zer)
        {
            out[id] = '1';
            bl++;
        }
        int j = 0;
        while (bl < n / 2)
        {
            if (out[j] == '0')
            {
                out[j] = '1';
                bl++;
            }
            j++;
        }
        cout << out;
    }
    else if (one.size() + two.size() <= n / 2)
    {
        printf("2\n");
        string out = "";
        frange(i, n) out += "0";
        int bl = 0;
        for (auto id : one)
        {
            out[id] = '1';
            bl++;
        }
        for (auto id : two)
        {
            out[id] = '1';
            bl++;
        }
        int j = 0;
        while (bl < n / 2)
        {
            if (out[j] == '0')
            {
                out[j] = '1';
                bl++;
            }
            j++;
        }
        cout << out;
    }
    else
    {
        printf("-1");
    }
}