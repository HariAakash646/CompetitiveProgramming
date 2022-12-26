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

    int t;
    scd(t);
    int n;
    string s;
    string p(100000000);
    frange(i, t)
    {
        scd(n);

        cin >> s;
        p = "";
        bool pf = false;
        forr(j, 1, n + 1, 1)
        {
            if (pf)
                p.insert(p.begin(), s[j - 1]);
            else
                p.push_back(s[j - 1]);
            if (j % 2 == 1)
                pf = (pf) ? false : true;
        }
        if (pf)
        {
            reverse(p.begin(), p.end());
        }
        cout << p << "\n";
    }

    return 0;
}