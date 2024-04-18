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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        vi vec(n + 1);
        vll pref(n + 1);
        frange(i, n)
        {
            cin >> vec[i + 1];
            pref[i + 1] = pref[i] + vec[i + 1];
        }
        int l = 1;
        int r = n;
        while (l != r)
        {
            int mid = (l + r) / 2;
            cout << "? " << mid - l + 1 << " ";
            forr(j, l, mid + 1)
            {
                cout << j << " ";
            }
            cout << endl;
            lli x;
            cin >> x;
            if (x > pref[mid] - pref[l - 1])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << "! " << l << endl;
    }
}