#include <iostream>
#include <bits/stdc++.h>

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
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

vector<int64> table{0};
int64 n, k;
int64 min_option(const vector<int64> &vec)
{
    int64 mini = 1000000001;
    int64 s = vec.size();
    int64 l = vec[s - 1];
    int64 mx = (0 > s - k) ? 0 : s - k - 1;
    forr(i, mx, s - 1, 1)
    {
        mini = (mini < table[i] + abs(vec[i] - l)) ? mini : table[i] + abs(vec[i] - l);
    }
    return mini;
}

int main()
{
    sclld(n);
    sclld(k);
    int64 a;
    int64 m;
    vector<int64> vec;
    frange(j, n)
    {
        sclld(a);
        vec.PB(a);
        if (j >= 1)
        {
            m = min_option(vec);
            table.PB(m);
        }
    }
    printf("%lld", table[n - 1]);

    return 0;
}