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
#define pb push_back
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
    int n, k;
    scd(n);
    scd(k);
    vi vec(n);
    deque<int> win;
    seti winset;
    multiset<int> winmset;
    int a;
    frange(i, n)
    {
        scd(a);
        vec[i] = a;
    }
    lli c = 0;
    forr(i, 0, n, 1)
    {
        win.pb(vec[i]);
        winset.insert(vec[i]);
        winmset.insert(vec[i]);

        while (winset.size() > k)
        {
            int v = win.front();
            win.pop_front();
            winmset.erase(winmset.find(v));
            auto itr = winmset.find(v);
            if (itr == winmset.end())
                winset.erase(v);
        }
        c += win.size();
    }
    printf("%lld", c);
}