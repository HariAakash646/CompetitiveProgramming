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
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vi pos(n);
    frange(i, n) scd(pos[i]);
    sort(all(pos));
    frange(i, k)
    {
        lli a, b;
        sclld(a);
        sclld(b);

        int n1 = 0, n2 = 0;
        lli tot = 0;
        while (n1 < n)
        {
            long double prev = 0;
            n2 = n1 + 1;
            while (n2 < n && prev + a >= double(pos[n2] - pos[n1]) / 2.0 * b)
            {
                prev = double(pos[n2] - pos[n1]) / 2.0 * b;
                n2++;
                if (n2 >= n)
                    break;
            }
            n1 = n2;
            tot += prev * 2 + a * 2;
        }
        // if (n1 == n - 1)
        //     tot += a * 2;
        printf("%lld\n", tot);
    }
}