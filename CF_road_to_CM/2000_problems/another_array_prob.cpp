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
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        vll vec(n);
        int ma = 0;
        int mid = 0;

        frange(i, n)
        {
            cin >> vec[i];
            if (vec[i] >= ma)
            {
                if (vec[i] == ma)
                {
                    if (i != 1 && i != n - 2)
                        mid = i;
                }
                else
                    mid = i;
                ma = vec[i];
            }
        }

        if (n == 2)
            cout << max(vec[0] + vec[1], 2 * (abs(vec[1] - vec[0]))) << "\n";
        else if (mid != 1 && mid != n - 2)
        {
            cout << lli(ma) * n << "\n";
        }
        else if (n == 3)
        {
            lli v = vec[0] + vec[1] + vec[2];
            lli x = min(vec[0], vec[2]);
            lli x2 = max(vec[0], vec[2]);

            cout << max(max(v, 3 * (vec[1] - x)), 3 * x2) << "\n";
        }
        else
        {
            lli v = lli(ma) * n;

            cout << v << "\n";
        }
    }
}