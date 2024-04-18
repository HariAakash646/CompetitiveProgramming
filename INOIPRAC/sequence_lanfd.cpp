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

vector<seti> peop;
vi memo;
int n, k;

int rec(int idx)
{
    if (memo[idx] != -1)
        return 0;
    memo[idx] = 1;
    frange(i, n)
    {
        if (i == idx || memo[i] != -1)
            continue;
        vi sl(n);
        auto ls = set_intersection(all(peop[idx]), all(peop[i]), sl.begin());
        if (ls - sl.begin() >= k)
        {
            memo[idx] += rec(i);
        }
    }
    return memo[idx];
}

int main()
{

    scd(n);
    scd(k);
    memo = vi(n, -1);
    int p, a;
    peop = vector<seti>(n);
    frange(i, n)
    {
        scd(p);
        frange(j, p)
        {
            scd(a);
            peop[i].insert(a);
        }
    }
    printf("%d", rec(0));
}