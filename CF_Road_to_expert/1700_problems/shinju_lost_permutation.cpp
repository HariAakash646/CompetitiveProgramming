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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
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
        vi vec(n);
        int id = -1;
        bool done = true;
        frange(i, n)
        {
            scd(vec[i]);
            if (vec[i] == 1)
            {
                if (id == -1)
                {
                    id = i;
                }
                else
                {
                    done = false;
                }
            }
        }
        if (id == -1)
        {
            done = false;
            id = 0;
        }
        vi v2;
        forr(i, id, n)
        {
            v2.pb(vec[i]);
        }
        forr(i, 0, id)
        {
            v2.pb(vec[i]);
        }
        int mi = 2;
        int ma = 2;
        forr(i, 1, n)
        {
            if (mi <= v2[i] && v2[i] <= ma)
            {
                mi = 2;
                ma = v2[i] + 1;
            }
            else
            {
                done = false;
            }
        }
        if (done)
            printf("YES\n");
        else
            printf("NO\n");
    }
}