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
        int n, k;
        cin >> n >> k;

        if (k % 2)
        {
            vector<char> v1, v2;
            string str;
            cin >> str;
            frange(i, n)
            {
                if (i % 2 == 0)
                {
                    v1.pb(str[i]);
                }
                else
                {

                    v2.pb(str[i]);
                }
            }
            sort(all(v1));
            sort(all(v2));
            int i1 = 0, i2 = 0;
            frange(i, n)
            {
                if (i % 2 == 0)
                {
                    cout << v1[i1];
                    i1++;
                }
                else
                {
                    cout << v2[i2];
                    i2++;
                }
            }
        }
        else
        {
            vector<char> v;
            string str;
            cin >> str;
            frange(i, n) v.pb(str[i]);
            sort(all(v));
            for (char e : v)
                cout << e;
        }
        cout << "\n";
    }
}