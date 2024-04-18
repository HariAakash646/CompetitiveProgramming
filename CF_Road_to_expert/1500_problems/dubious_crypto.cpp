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
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int l, r;
        lli m;
        scd(l);
        scd(r);
        sclld(m);

        forr(i, l, r + 1)
        {
            lli nt = (m + r - l) / i;
            if (nt > 0 && nt * i >= m - r + l && nt * i <= m + r - l)
            {
                if (m <= nt * i)
                {
                    int b = l;
                    int c = l + nt * i - m;
                    printf("%d %d %d\n", i, b, c);
                }
                else
                {
                    int b = l + nt * i - m;
                    int c = l;
                }

                // if (v < 0)
                //     swap(b, c);
            }
        }
    }
}