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
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
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
    frange(_, t)
    {
        int t1, t2, t3, t4;
        scd(t1);
        scd(t2);
        scd(t3);
        scd(t4);
        int a = 0;
        int b = 0;
        int tot = 0;
        tot += t1;
        a += t1;
        b += t1;
        if (t2 < t3)
            swap(t2, t3);
        tot += 2 * t3;
        t2 -= t3;
        tot += min(b, t2);
        b -= t2;
        if (b < 0)
        {
            tot++;
        }
        if (b == 0)
        {
            if (t4)
                tot++;
        }
        if (b > 0)
        {
            tot += min(b, t4);
            b -= t4;
            if (b < 0)
                tot++;
        }

        if (t1 == 0 && tot > 0)
            printf("1\n");
        else
            printf("%d\n", tot);
    }
}