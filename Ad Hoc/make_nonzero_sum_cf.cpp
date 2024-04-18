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
        vi vec(n);
        int sum = 0;
        frange(i, n)
        {
            scd(vec[i]);
            sum += vec[i];
        }
        if (sum % 2)
        {
            printf("-1\n");
            continue;
        }

        vii part;
        int id1 = 0;
        int one = 0;
        int su = 0;
        frange(i, n)
        {
            if (vec[i])
                one++;
            if (((i - id1) % 2) == 0)
            {
                su += vec[i];
            }
            else
                su -= vec[i];
            if (one == 2)
            {
                if (su == 0)
                {
                    part.pb({id1, i});
                }
                else
                {
                    if (((i - id1) % 2))
                    {
                        part.pb({id1, i - 1});
                        part.pb({i, i});
                    }
                    else
                    {
                        part.pb({id1, id1});
                        if (vec[id1])
                        {
                            part.pb({id1 + 1, i});
                        }
                        else
                        {
                            part.pb({id1 + 1, i - 1});
                            part.pb({i, i});
                        }
                    }
                }
                one = 0;
                su = 0;
                id1 = i + 1;
            }
        }
        if (id1 <= n - 1)
        {
            part.pb({id1, n - 1});
        }
        printf("%d\n", part.size());
        for (auto p : part)
        {
            printf("%d %d\n", p.f + 1, p.s + 1);
        }
    }
}