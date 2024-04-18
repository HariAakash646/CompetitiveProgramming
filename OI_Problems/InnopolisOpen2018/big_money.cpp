#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    lli m;
    int n;
    cin >> m >> n;
    cout << fixed << setprecision(9);
    frange(i, n)
    {
        lli l1, h1, l2, h2;
        lli p1, p2;
        cin >> l1 >> h1 >> p1 >> l2 >> h2 >> p2;
        // p1 /= 100;
        // p2 /= 100;
        if (l2 < l1)
        {
            swap(l1, l2);
            swap(h1, h2);
            swap(p1, p2);
        }
        vector<pair<pii, lli>> vec;
        if (l2 <= h1)
        {
            if (l1 != l2)
                vec.pb(mp(mp(l1, l2 - 1), p1));
            if (h2 < h1)
            {
                if (l2 != h2)
                    vec.pb(mp(mp(l2, h2), max(p1, p2)));
                vec.pb(mp(mp(h2 + 1, h1), p1));
            }
            else
            {
                vec.pb(mp(mp(l2, h1), max(p1, p2)));
                if (h1 != h2)
                    vec.pb(mp(mp(h1 + 1, h2), p2));
            }
        }
        else
        {
            vec.pb(mp(mp(l1, h1), p1));
            vec.pb(mp(mp(l2, h2), p2));
        }
        lli v = 0;
        int k = vec.size();
        frange(j, pow(3, k))
        {
            lli x = m;
            int l = j;
            lli vt = 0;
            frange(i, k)
            {
                if (l % 3 == 1)
                {
                    vt +=
                        x -= vec[i].f.f;
                }
            }
        }
        cout << m + ld(v) / 100 << "\n";
    }
}