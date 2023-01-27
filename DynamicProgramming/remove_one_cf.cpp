// Incorrect
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
    int n;
    scd(n);
    vi vec(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    vi dp1(n + 1);
    vi dp2(n + 1);
    int j = 0;
    forr(i, 1, n + 1)
    {
        if (vec[i] > vec[j])
        {
            dp2[i] = dp2[i - 1] + 1;
            j = i - 1;
        }
        if (vec[i] > vec[i - 1])
        {
            dp1[i] = dp1[i - 1] + 1;
            j = i - 1;
        }

        else
        {
            dp1[i] = 1;
            if (dp1[i - 1] > dp1[i - 2] + 1)
                j = i - 1;
            else
                j = i - 2;
            dp2[i] = max(dp1[i - 1], dp1[i - 2] + 1);
        }
    }
    printf("%d", max(*max_element(all(dp2)), *max_element(all(dp1))));
}