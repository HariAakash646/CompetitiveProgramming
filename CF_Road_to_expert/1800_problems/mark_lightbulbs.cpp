// Incorrect
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n;

bool flip(int i, int x, int &c, int d, vi &vec)
{
    if (i == x)
        return false;
    bool out = true;
    c++;
    // printf("%d %d\n", c, i);
    if (vec[i + 1] == vec[i - 1])
    {
        out = flip(i + d, x, c, d, vec);
    }
    vec[i] = !vec[i];
    return out;
}

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {

        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vi v1, v2;

        forr(i, 1, n - 1)
        {
            if (s1[i] == '1')
                v1.pb(i);
            if (s2[i] == '1')
                v2.pb(i);
        }
        if (s1[0] != s2[0] || s1[n - 1] != s2[n - 1] || v1.size() != v2.size())
            printf("-1\n");
        else
        {
            int tot = 0;
            frange(i, v1.size())
            {
                tot += abs(v1[i] - v2[i]);
            }
            printf("%d\n", tot);
        }
    }
}