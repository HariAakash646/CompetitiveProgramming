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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int v1 = 0;
        frange(i, n)
        {
            if (s1[i] != s2[i])
                v1++;
        }
        if (v1 % 2)
            v1 += v1 - 1;
        else
            v1 += v1;
        int v2 = 1e9;
        if (n > 1)
        {
            reverse(all(s1));
            v2 = 0;
            frange(i, n)
            {
                if (s1[i] != s2[i])
                    v2++;
            }
            if (v2 % 2)
                v2 += v2;
            else
                v2 += v2 - 1;
            v2 = max(2, v2);
        }
        cout << min(v1, v2) << "\n";
    }
}