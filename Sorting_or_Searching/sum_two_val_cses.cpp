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
    int n, x;
    scd(n);
    scd(x);
    vi vec(n);

    frange(i, n)
    {
        scd(vec[i]);
    }
    vi vec_copy = vec;
    sort(vec.begin(), vec.end());
    auto itr = vec.begin();
    auto itr2 = vec.begin();
    while (itr != vec.end())
    {
        itr2 = lower_bound(itr + 1, vec.end(), x - (*itr));
        if (itr2 != vec.end() && (*itr) + (*itr2) == x)
        {
            auto pos1 = find(vec_copy.begin(), vec_copy.end(), *itr);
            auto pos2 = find(vec_copy.begin(), vec_copy.end(), *itr2);
            if (pos1 == pos2)
                pos2 = find(pos1 + 1, vec_copy.end(), *itr2);
            printf("%d %d", pos1 - vec_copy.begin() + 1, pos2 - vec_copy.begin() + 1);
            return 0;
        }
        itr++;
    }

    printf("IMPOSSIBLE");
    return 0;
}