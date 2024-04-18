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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int n;
    cin >> n;
    vi vec(n);
    frange(i, n) cin >> vec[i];
    string str;
    cin >> str;
    vll m(3);
    vll e(3);
    vll x(3);
    frange(i, n)
    {
        if (str[i] == 'M')
            m[vec[i]]++;
        if (str[i] == 'E')
            e[vec[i]]++;
        if (str[i] == 'X')
            x[vec[i]]++;
    }
    lli sum = 0;

    frange(i, n)
    {
        if (str[i] == 'M')
        {
            if (vec[i] == 0)
            {
                sum += e[0] * x[0] + e[0] * x[2] + e[2] * x[0] + e[2] * x[2];
                sum += 2 * (e[0] * x[1] + e[1] * x[0] + e[1] * x[1]);
                sum += 3 * (e[1] * x[2] + e[2] * x[1]);
            }
            else if (vec[i] == 1)
            {
                sum += 2 * (e[0] * x[1] + e[0] * x[0] + e[1] * x[0]);
                sum += 3 * (e[0] * x[2] + e[2] * x[0]);
            }
            else
            {
                sum += (e[0] * x[2] + e[2] * x[0] + e[0] * x[0]);
                sum += 3 * (e[0] * x[1] + e[1] * x[0]);
            }
            m[vec[i]]--;
            // cout << i << " " << sum << "\n";
        }
        else if (str[i] == 'E')
            e[vec[i]]--;
        else
            x[vec[i]]--;
    }
    cout << sum;
}