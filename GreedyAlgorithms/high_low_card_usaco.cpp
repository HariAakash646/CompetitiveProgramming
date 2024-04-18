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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    scd(n);
    seti bes, els;
    vi el;
    int a;
    frange(i, n)
    {
        scd(a);
        el.PB(a);
        els.insert(a);
    }
    forr(i, 1, 2 * n + 1, 1)
    {
        auto bin = els.find(i);
        if (bin == els.end())
        {
            bes.insert(i);
        }
    }
    seti bes1;
    seti bes2;
    int k = 1;
    for (auto e : bes)
    {
        if (k <= n / 2)
            bes2.insert(e);
        else
            bes1.insert(e);
        k++;
    }
    int j = 1;
    int win = 0;
    for (auto e : el)
    {

        if (j <= n / 2)
        {
            auto itr = bes1.upper_bound(e);
            if (itr != bes1.end())
            {
                win++;
                bes1.erase(itr);
            }
        }
        else
        {
            auto itr = bes2.upper_bound(e);
            if (itr != bes2.begin())
            {
                win++;
                itr--;
                bes2.erase(itr);
            }
        }
        j++;
    }
    cout << win;
}