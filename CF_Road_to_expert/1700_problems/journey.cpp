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

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vi vec(n);
        frange(i, n)
        {
            if (str[i] == 'R')
                vec[i] = 1;
        }
        vi evel(n + 1, 1);
        vi oddl(n + 1, 1);
        forr(i, 1, n + 1)
        {
            if (vec[i - 1] == 0)
            {
                evel[i] += oddl[i - 1];
            }
            else
            {
                oddl[i] += evel[i - 1];
            }
        }
        vi ever(n + 1, 1);
        vi oddr(n + 1, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            if (vec[i] == 1)
            {
                ever[i] += oddr[i + 1];
            }
            else
            {
                oddr[i] += ever[i + 1];
            }
        }
        frange(i, n + 1)
        {
            printf("%d ", evel[i] + ever[i] - 1);
        }
        printf("\n");
    }
}