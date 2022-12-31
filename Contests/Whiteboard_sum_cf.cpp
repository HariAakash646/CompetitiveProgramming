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
    while (t--)
    {
        int n, m;
        scd(n);
        scd(m);
        vector<lli> vec(n);
        frange(i, n) sclld(vec[i]);
        lli b;
        frange(i, m)
        {
            sclld(b);
            lli min_ele, min_idx;
            min_ele = 1e9 + 5;
            frange(j, n)
            {
                if (vec[j] <= min_ele)
                {
                    min_ele = vec[j];
                    min_idx = j;
                }
            }
            vec[min_idx] = b;
        }
        lli s = 0;
        for (auto i : vec)
            s += i;
        cout << s << "\n";
    }
}