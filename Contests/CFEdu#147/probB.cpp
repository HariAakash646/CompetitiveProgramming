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
        vi v1(n), v2(n);
        frange(i, n)
        {
            scd(v1[i]);
        }
        frange(i, n) scd(v2[i]);
        int id;
        frange(i, n)
        {
            if (v1[i] != v2[i])
            {
                id = i;
                break;
            }
        }
        int st = id;
        for (int i = id - 1; i >= 0; i--)
        {
            if (v2[i] <= v2[i + 1])
            {
                st--;
            }
            else
                break;
        }
        int en = id;
        forr(i, id + 1, n)
        {
            if (v2[i] >= v2[i - 1])
            {
                en++;
            }
            else
                break;
        }
        printf("%d %d\n", st + 1, en + 1);
    }
}