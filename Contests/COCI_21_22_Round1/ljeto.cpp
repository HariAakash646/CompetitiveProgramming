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
    int n;
    scd(n);

    int pin = 0;
    int blue = 0;

    vi spray(1001);

    frange(i, n)
    {
        int a, b, t;
        scd(t);
        scd(a);
        scd(b);

        int pre = 0;
        forr(j, t - 10, t)
        {
            if (spray[j] == a)
                pre = 1;
        }
        if (a <= 4)
            pin += 100 + pre * 50;
        else
            blue += 100 + pre * 50;
        spray[t] = a;
    }
    printf("%d %d", pin, blue);
}