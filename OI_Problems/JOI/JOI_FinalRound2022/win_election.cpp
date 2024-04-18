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

ld inf = 1e9;

bool cmp(pair<ld, ld> x, pair<ld, ld> y)
{
    return x.s < y.s;
}

int main()
{
    int n, k;
    scd(n);
    scd(k);

    vector<vector<ld>> prev(k + 1, vector<ld>(k + 2, inf)), curr(k + 1, vector<ld>(k + 2, inf));
    vector<pair<ld, ld>> vec(n);
    frange(i, n)
    {
        cin >> vec[i].f >> vec[i].s;
        if (int(vec[i].s) == -1)
            vec[i].s = inf;
    }
    sort(all(vec), cmp);
    prev[0][1] = 0;
    prev[1][1] = vec[0].f;
    if (vec[0].s != inf)
        prev[1][2] = vec[0].s;

    forr(i, 1, n)
    {
        curr = vector<vector<ld>>(k + 1, vector<ld>(k + 2, inf));
        curr[0][1] = 0;
        forr(j, 1, k + 1)
        {
            forr(l, 1, j + 2)
            {
                curr[j][l] = min(prev[j][l], prev[j - 1][l] + vec[i].f / ld(l));
                if (l >= 2 && vec[i].s != inf)
                {
                    curr[j][l] = min(curr[j][l], prev[j - 1][l - 1] + vec[i].s / ld(l - 1));
                }
            }
        }
        prev = curr;
    }
    cout << fixed << setprecision(3) << *min_element(all(prev[k]));
}