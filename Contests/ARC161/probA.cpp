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
    vi vec(n);
    frange(i, n) scd(vec[i]);
    sort(all(vec));

    bool done = true;
    int mid = (n + 1) / 2;

    if (n == 1)
    {
        printf("Yes");
        return 0;
    }
    if (vec[0] >= vec[mid] || vec[1] >= vec[mid])
    {
        done = false;
    }
    int id = 2;
    forr(i, mid + 1, n)
    {
        if (vec[id] >= vec[i])
        {
            done = false;
            break;
        }
        id++;
    }
    if (done)
        printf("Yes");
    else
        printf("No");
}