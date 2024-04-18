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
#define MP make_pair
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

int main()
{
    string str;
    cin >> str;
    vii ab;
    vii ba;
    frange(i, str.size() - 1)
    {
        if (str[i] == 'A' && str[i + 1] == 'B')
        {
            ab.pb({i, i + 1});
        }
        else if (str[i] == 'B' && str[i + 1] == 'A')
        {
            ba.pb({i, i + 1});
        }
    }
    if (ab.size() == 0 || ba.size() == 0)
    {
        printf("NO");
        return 0;
    }
    if (ab.size() > 2 || ba.size() > 2)
    {
        printf("YES");
        return 0;
    }
    for (auto e : ab)
    {
        for (auto p : ba)
        {
            if (e.f != p.s && e.s != p.f)
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
}