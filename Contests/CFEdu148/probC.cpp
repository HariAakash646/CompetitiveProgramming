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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
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
        int cont = 0;
        frange(i, n)
        {
            scd(vec[i]);
            if (i > 0)
                cont += abs(vec[i] - vec[i - 1]);
        }
        if (cont == 0)
        {
            printf("1\n");
            continue;
        }

        int curr = 0;
        bool asc;
        if (vec[1] > vec[0])
            asc = true;
        else
            asc = false;
        int rem = 0;
        forr(i, 1, n)
        {
            if (asc)
            {
                if (vec[i] < vec[i - 1])
                {
                    rem += (i - 1) - curr - 1;
                    if (vec[i - 1] == vec[curr])
                        rem++;
                    curr = i - 1;
                    asc = false;
                }
            }
            else
            {
                if (vec[i] > vec[i - 1])
                {
                    rem += (i - 1) - curr - 1;
                    if (vec[i - 1] == vec[curr])
                        rem++;
                    curr = i - 1;
                    asc = true;
                }
            }
        }
        rem += (n - 1) - curr - 1;
        if (vec[n - 1] == vec[curr])
            rem++;
        printf("%d\n", n - rem);
    }
}