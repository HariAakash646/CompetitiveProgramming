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

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string str;
    cin >> str;
    int p = 0;
    int m = 0;
    for (auto e : str)
    {
        if (e == '+')
            p++;
        else if (e == '-')
            m++;
    }
    int q;
    cin >> q;
    frange(_, q)
    {
        lli a, b;
        cin >> a >> b;
        lli tot = p - m;
        if (tot == 0)
        {
            printf("YES\n");
            continue;
        }
        if (a == b)
        {
            printf("NO\n");
            continue;
        }
        if (a < b)
            swap(a, b);
        lli v = tot * a;
        if (v % (a - b) == 0 && -m <= v / (a - b) && v / (a - b) <= p)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}