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
    int n, t;
    scd(n);
    scd(t);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    auto ptr1 = vec.begin();
    auto ptr2 = ptr1;
    int mb = 0;
    int time = *ptr1;
    while (true)
    {

        while (time <= t)
        {
            ptr2++;
            if (ptr2 == vec.end())
            {
                break;
            }
            time = time + *(ptr2);
        }
        time = time - (*ptr1) - *ptr2;
        ptr2--;
        mb = max((int)(ptr2 - ptr1) + 1, mb);

        ptr1++;
        if (ptr1 == vec.end())
            break;
    }
    printf("%d", mb);
}