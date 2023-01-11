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
#define PB push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
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
    vii vec(n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    frange(i, n)
    {
        vec[i] = {i + 1, (i + 1) % n};
    }
    int prev = 0;
    int idx = 1;
    frange(i, n)
    {
        pii curr = vec[idx];
        vec[prev].s = vec[idx].s;
        printf("%d ", vec[idx].f);
        prev = vec[idx].s;
        idx = vec[prev].s;
    }
}