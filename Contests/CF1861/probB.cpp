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
    int t;
    cin >> t;

    frange(_, t)
    {
        string n1, n2;
        cin >> n1 >> n2;

        int n = n1.size();

        if (n1[0] != n2[0] || n1[n - 1] != n2[n - 1])
        {
            cout << "NO\n";
            continue;
        }

        if (n1[0] == n1[n - 1])
        {
            cout << "YES\n";
            continue;
        }

        vi dif;
        vi zer, on;

        frange(i, n)
        {
            if (n1[i] != n2[i])
            {
                dif.pb(i);
            }
            else
            {
                if (n1[i] == '0')
                    zer.pb(i);
                else
                    on.pb(i);
            }
        }

        if (n1[0] == 1)
            swap(zer, on);
        bool done = false;
        for (auto e : zer)
        {
            int v = *upper_bound(all(on), e);

            if (!(upper_bound(all(dif), v) - lower_bound(all(dif), e)))
                done = true;
        }

        if (!done)
            cout << ("NO\n");
        else
            cout << "YES\n";
    }
}