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
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    scd(n);
    vi vec(n);
    frange(i, n)
    {
        scd(vec.at(i));
    }
    int s = vec.size();
    int swaps = 0;
    for (int i = s - 1; i > 0;)
    {
        if (vec.at(i) >= vec.at(i - 1))
        {
            i--;
            continue;
        }
        int j = i - 1;
        while (j != 0 && vec.at(j) == vec.at(j - 1))
            j--;
        swap(vec.at(i), vec.at(j));
        i = j;
        swaps++;
    }

    cout << swaps;
}
