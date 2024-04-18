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
        int n;
        scd(n);
        vi avec(n);
        vi bvec(n);
        frange(i, n)
        {
            scd(avec[i]);
        }
        frange(i, n)
        {
            scd(bvec[i]);
        }
        seti prev;
        stack<int> stk;
        int out = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (prev.find(avec[j]) != prev.end())
            {
                j++;
            }
            if (avec[j] != bvec[i])
            {
                out = i + 1;
            }
            else
                j++;

            prev.insert(bvec[i]);
        }
        printf("%d\n", out);
    }
}