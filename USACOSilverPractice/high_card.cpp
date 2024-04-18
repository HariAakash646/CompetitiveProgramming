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
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    scd(n);
    vi vec(n);
    seti cards;
    forr(i, 1, 2 * n + 1)
    {
        cards.insert(i);
    }
    frange(i, n)
    {
        scd(vec[i]);
        cards.erase(vec[i]);
    }
    int c = 0;
    for (auto e : vec)
    {
        auto itr = cards.upper_bound(e);
        if (itr == cards.end())
        {
            cards.erase(cards.begin());
        }
        else
        {
            cards.erase(itr);
            c++;
        }
    }
    printf("%d", c);
}