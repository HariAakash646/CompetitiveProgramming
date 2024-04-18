#include <bits/stdc++.h>

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
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vll vec(n);
        frange(i, n) sclld(vec[i]);
        // vec1 = vec;
        vec[0] -= 2e10;
        vec[1] -= 2e10;
        vec[n - 1] += 2e10;
        vec[n - 2] += 2e10;
        forr(i, 1, n - 1)
        {
            if (vec[i] < vec[i - 1])
            {
                lli d = vec[i - 1] - vec[i];
                vec[i] = vec[i - 1];
                vec[i + 1] += d;
            }
            else if (vec[i] > vec[i - 1])
            {
                lli d = vec[i] - vec[i - 1];
                vec[i] = vec[i - 1];
                vec[i + 1] -= d;
            }
        }
        for (int i = n - 2; i >= 1; i--)
        {
            if (vec[i] > vec[i + 1])
            {
                lli d = vec[i] - vec[i + 1];
                vec[i] = vec[i + 1];
                vec[i - 1] -= d;
            }
            else if (vec[i] < vec[i + 1])
            {
                lli d = vec[i + 1] - vec[i];
                vec[i] = vec[i + 1];
                vec[i - 1] += d;
            }
        }
        forr(i, 1, n - 1)
        {
            if (vec[i] < vec[i - 1])
            {
                lli d = vec[i - 1] - vec[i];
                vec[i] = vec[i - 1];
                vec[i + 1] += d;
            }
            else if (vec[i] > vec[i - 1])
            {
                lli d = vec[i] - vec[i - 1];
                vec[i] = vec[i - 1];
                vec[i + 1] -= d;
            }
        }
        for (int i = n - 2; i >= 1; i--)
        {
            if (vec[i] > vec[i + 1])
            {
                lli d = vec[i] - vec[i + 1];
                vec[i] = vec[i + 1];
                vec[i - 1] -= d;
            }
            else if (vec[i] < vec[i + 1])
            {
                lli d = vec[i + 1] - vec[i];
                vec[i] = vec[i + 1];
                vec[i - 1] += d;
            }
        }
        // for (auto e : vec)
        // {
        //     printf("%lld ", e);
        // }
        // printf("\n");
        if (vec[0] > vec[1])
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}