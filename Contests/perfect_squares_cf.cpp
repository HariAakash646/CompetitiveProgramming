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

bool check_sqr(lli k)
{
    lli sq = sqrt(k);
    return sq * sq == k;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vector<lli> vec(n, 0LL);
        frange(i, n) sclld(vec[i]);
        if (n == 1)
        {
            printf("%d\n", 1);
            continue;
        }
        int m = 1;
        frange(i, n)
        {
            frange(j, n)
            {
                lli v = max(0LL, vec[j] - vec[i]);
                if (v % 2 == 1)
                {
                    lli l = v / 2;
                    lli r = l + 1;
                    lli diff = l * l - vec[i];
                    int c = 0;
                    if (diff >= 0)
                    {
                        frange(e, n)
                        {
                            if (check_sqr(vec[e] + diff))
                                c++;
                        }
                        m = max(m, c);
                    }
                }
                else
                {
                    lli l = v / 2;
                    lli r = l + 1;

                    frange(diff, r)
                    {
                        int c = 0;
                        if (diff >= 0)
                        {
                            frange(e, n)
                            {
                                if (check_sqr(vec[e] + diff))
                                    c++;
                            }
                            m = max(m, c);
                        }
                    }
                }
            }
        }

        printf("%d\n", m);
    }
}