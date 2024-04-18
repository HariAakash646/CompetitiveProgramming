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

lli mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int c = 0;
        lli tot = 1;
        lli cons = 1;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};

        frange(i, n)
        {
            if (st.find(str[i]) != st.end())
            {
                c++;
            }
            else if (c == k)
                cons++;
            if (c == k + 1)
            {
                c = 1;
                tot *= cons;
                tot %= mod;
                cons = 1;
            }
        }
        printf("%lld\n", tot);
    }
}