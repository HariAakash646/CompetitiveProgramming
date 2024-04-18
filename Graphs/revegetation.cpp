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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
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

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    scd(n);
    scd(m);
    vvi vec(n + 1);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        vec[a].PB(b);
        vec[b].PB(a);
    }
    vi valvec(n + 1, 0);
    forr(i, 1, n + 1, 1)
    {
        seti seeds{1, 2, 3, 4};
        for (int j : vec[i])
        {
            seeds.erase(valvec[j]);
        }
        valvec[i] = *seeds.begin();
        printf("%d", valvec[i]);
    }
    return 0;
}