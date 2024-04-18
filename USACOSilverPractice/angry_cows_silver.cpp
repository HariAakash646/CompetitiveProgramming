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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n, k;
vi pos;

bool check(int r)
{
    if (r == 0)
        return n == 1;
    // int val = (pos[n - 1] - pos[0] - r) / (2 * r) + ((pos[n - 1] - pos[0] - r) % (2 * r) > 0);
    int curr = pos[0];
    int val = 1;
    while (true)
    {
        auto itr = upper_bound(all(pos), curr + 2 * r);
        if (itr == pos.end())
            break;
        curr = *itr;
        val++;
        if (val > k)
            return false;
    }
    return true;
}

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    scd(n);
    scd(k);
    frange(i, n)
    {
        int a;
        scd(a);
        pos.pb(a);
        
    }
    sort(all(pos));
    int hi = (pos[n - 1] - pos[0] + 1) / 2;
    int lo = 0;
    while (lo != hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    printf("%d", lo);
}