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

#define f first
#define s second

pair<int, int> insert(int x);

vi findset(int n, int initTri, int initStr, int subTask)
{
    vi vec(n);
    if (initStr > 2)
    {
        forr(i, 1, n)
        {
            pii out = insert(i);
            if (out.s > initStr)
            {
                vec[i] = 4;
            }
        }
    }
    else if (initStr == 1)
    {
        int o1;
        forr(i, 1, n)
        {
            pii out = insert(i);
            if (out.s > initStr)
            {
                vec[i - 1] = 3;
                o1 = i - 1;
            }
        }
        forr(i, 1, n)
        {
            pii out = insert(i);
            if (out.f == 1)
            {
                vec[(o1 + i - 1) / 2] = 1;
            }
        }
    }
    else
    {
        int o1;
        forr(i, 1, n)
        {
            pii out = insert(i);
            if (out.s > initStr)
            {
                vec[i - 1] = 2;
                o1 = i - 1;
            }
        }
        if (initTri == 1)
        {
            if (o1 == 0)
            {
                vec[1] += 1;
                vec[2] += 1;
            }
            else if (o1 == 3)
            {
                vec[1] += 1;
                vec[2] += 1;
            }
        }
    }
    return vec;
}