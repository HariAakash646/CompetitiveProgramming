#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCLLU(t) scanf("%llu", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define for_range(i, j) FOR(i, 0, j, 1)
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

bool check_x(int64 x, int m, const vector<int> &vec)
{
    int64 t = 0;
    int l = 1;
    for (int e : vec)
    {
        t += e;
        if (t > x)
        {
            t = e;
            l++;
        }
        if (l > m)
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    SCD(n);
    SCD(m);
    vector<int> vec(n);
    for_range(i, n) SCD(vec[i]);
    int64 l = *max_element(vec.begin(), vec.end());
    int64 r = accumulate(vec.begin(), vec.end(), 0LL);
    while (l != r)
    {
        int64 k = (l + r) / 2;
        if (check_x(k, m, vec))
            r = k;
        else
            l = k + 1;
    }
    printf("%lld", r);
}