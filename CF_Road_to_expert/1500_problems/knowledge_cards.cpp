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
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        vi vec(k);
        frange(i, k)
        {
            scd(vec[i]);
        }
        int curr = k;
        vb done(k + 1);
        bool suc = true;
        int c = 0;
        for (auto e : vec)
        {
            if (e == curr)
            {
                done[k] = true;
                curr--;
                while (done[curr])
                {
                    curr--;
                    c--;
                }
            }
            else
            {
                done[e] = true;
                c++;
            }
            if (c >= n * m - 3)
            {
                printf("TIDAK\n");
                suc = false;
                break;
            }
        }
        if (suc)
        {
            printf("YA\n");
        }
    }
}