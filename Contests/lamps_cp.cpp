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
typedef vector<bool> vb;
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
    int t;
    scd(t);

    frange(i, t)
    {
        int n;
        scd(n);
        string lamps;
        cin >> lamps;
        auto itrl = lamps.find_last_of('L');
        auto itrr = lamps.find('R');
        if (itrl == string::npos || itrr == string::npos)
        {
            cout << -1 << "\n";
        }
        else if (itrl < itrr)
        {
            cout << itrr << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}