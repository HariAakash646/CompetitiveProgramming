#include <bits/stdc++.h>
#include <iostream>

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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        vi out;
        vi v1(n), v2(n);
        frange(i, n)
        {
            if (s1[i] == '1')
                v1[i] = 1;
            if (s2[i] == '1')
                v2[i] = 1;
        }
        int curr = v1[0];
        forr(i, 1, n)
        {
            if (v1[i] != v1[i - 1])
            {
                curr = !curr;
                out.pb(i);
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (v2[i] != curr)
            {
                curr = !curr;
                out.pb(i + 1);
            }
        }
        cout << out.size() << " ";
        for (auto e : out)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
}