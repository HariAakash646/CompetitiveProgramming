// Not working
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
typedef vector<bool> vb;
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
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    scd(t);
    scd(a);
    scd(b);
    vb vec2(t + 1);
    vb vec1(t + 1);

    vec2[0] = vec1[0] = true;
    forr(i, 1, t + 1)
    {
        if (i - a >= 0)
            vec1[i] = vec1[i - a];
        if (i - b >= 0)
            vec1[i] = vec1[i] || vec1[i - b];
    }

    forr(i, 1, t + 1)
    {
        vec2[i] = vec1[i];
        if (2 * i <= t)
            vec2[i] = vec2[i] || vec1[2 * i];
        if (2 * i + 1 <= t)
            vec2[i] = vec2[i] || vec1[2 * i + 1];
        if (i - a >= 0)
            vec2[i] = vec2[i] || vec2[i - a];
        if (i - b >= 0)
            vec2[i] = vec2[i] || vec2[i - b];
    }

    int m = 0;
    frange(i, t + 1)
    {
        if (vec2[i])
            m = i;
    }
    printf("%d", m);
}