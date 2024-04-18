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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int m, r, n;
        cin >> m >> r >> n;
        vi vec(n);
        frange(i, n)
        {
            cin >> vec[i];
        }
        int curr = 0;
        int c = 0;
        cout << "Case #" << _ + 1 << ": ";
        while (curr < m)
        {
            auto itr = upper_bound(all(vec), curr + r);
            if (itr == vec.begin())
            {
                cout << "IMPOSSIBLE\n";
                c = -1;
                break;
            }
            c++;
            itr--;
            if (*itr + r <= curr)
            {
                cout << "IMPOSSIBLE\n";
                c = -1;
                break;
            }
            curr = *itr + r;
        }
        if (c != -1)
            cout << c << "\n";
    }
}