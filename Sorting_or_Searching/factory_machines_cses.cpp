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
typedef vector<long long> vi;
typedef vector<string> vs;
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

vi mac;
lli n, t;

bool check(lli r)
{
    lli tot = 0;
    for (auto e : mac)
    {
        tot += r / e;
    }
    return tot >= t;
}

int main()
{

    sclld(n);
    sclld(t);
    mac = vi(n);
    frange(i, n)
    {
        sclld(mac[i]);
    }
    lli l = 0;
    lli h = *min_element(all(mac)) * t;
    while (l != h)
    {
        lli mid = (l + h) / 2;
        bool out = check(mid);
        if (out)
            h = mid;
        else
            l = mid + 1;
        if (l > h)
        {
            printf("-1");
            return 0;
        }
    }
    printf("%lld", l);
}