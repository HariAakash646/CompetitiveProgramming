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
        vll vec(n);
        frange(i, n)
        {
            sclld(vec[i]);
        }
        lli sum1 = 0, sum2 = 0;
        bool upd = true;
        vll ogvec = vec;
        while (upd)
        {
            bool curr = false;
            forr(i, 1, n)
            {
                if (vec[i] < 0 && vec[i - 1] < 0)
                {

                    vec[i] = -vec[i];
                    vec[i - 1] = -vec[i - 1];
                    curr = true;
                }
                else if (vec[i] < 0)
                {
                    if (abs(vec[i]) > abs(vec[i - 1]))
                    {
                        vec[i] = -vec[i];
                        vec[i - 1] = -vec[i - 1];
                        curr = true;
                    }
                }
                else if (vec[i - 1] < 0)
                {
                    if (abs(vec[i - 1]) > abs(vec[i]))
                    {
                        vec[i] = -vec[i];
                        vec[i - 1] = -vec[i - 1];
                        curr = true;
                    }
                }
            }
            upd = curr;
        }
        for (lli e : vec)
        {
            sum1 += e;
        }
        upd = true;
        vec = ogvec;
        while (upd)
        {
            bool curr = false;
            for (int i = n - 1; i >= 1; i--)
            {
                if (vec[i] < 0 && vec[i - 1] < 0)
                {

                    vec[i] = -vec[i];
                    vec[i - 1] = -vec[i - 1];
                    curr = true;
                }
                else if (vec[i] < 0)
                {
                    if (abs(vec[i]) > abs(vec[i - 1]))
                    {
                        vec[i] = -vec[i];
                        vec[i - 1] = -vec[i - 1];
                        curr = true;
                    }
                }
                else if (vec[i - 1] < 0)
                {
                    if (abs(vec[i - 1]) > abs(vec[i]))
                    {
                        vec[i] = -vec[i];
                        vec[i - 1] = -vec[i - 1];
                        curr = true;
                    }
                }
            }
            upd = curr;
        }

        for (lli e : vec)
        {
            sum2 += e;
        }
        printf("%lld\n", max(sum1, sum2));
    }
}