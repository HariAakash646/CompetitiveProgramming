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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n + 1);
        frange(i, n)
        {
            scd(vec[i + 1]);
        }
        bool done = false;
        forr(i, 1, n)
        {
            lli v1 = 1;
            forr(j, 1, i + 1)
            {
                v1 += vec[j] == 2;
            }
            lli v2 = 1;
            forr(j, i + 1, n + 1)
            {
                v2 += vec[j] == 2;
            }
            if (v1 == v2)
            {
                printf("%d\n", i);
                done = true;
                break;
            }
        }
        if (!done)
        {
            printf("-1\n");
        }
    }
}