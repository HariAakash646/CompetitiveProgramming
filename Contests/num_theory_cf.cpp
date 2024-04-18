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
    frange(i, t)
    {
        int n;
        scd(n);
        vector<lli> vec(n);
        lli a;
        int odd = 1;
        frange(j, n)
        {
            sclld(a);
            vec[j] = a;
        }
        sort(vec.begin(), vec.end());
        vector<lli> diff;
        frange(j, n - 1)
        {
            forr(k, j + 1, n, 1)
            {
                diff.push_back(vec[k] - vec[j]);
            }
        }
        sort(diff.begin(), diff.end());
        bool dup = false;
        frange(j, diff.size() - 1)
        {
            if (diff[j] == diff[j + 1])
                dup = true;
        }
        if (dup)
            printf("NO\n");
        else
            printf("YES\n");
    }
}