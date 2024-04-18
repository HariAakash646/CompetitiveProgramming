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
        int n;
        cin >> n;
        string str;
        cin >> str;
        vi vec(n);

        int odd = 0;
        int id = -1;
        frange(i, n)
        {
            vec[i] = str[i] - '0';
            if (vec[i])
            {
                odd++;
                if (id == -1)
                    id = i;
            }
        }

        if (odd == 0 || odd % 2)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vi ne(n);
        id++;
        frange(i, n)
        {
            ne[i] = (i + id) % n;
        }
        int root = ne[0] + 1;
        bool r = true;
        vii edges;
        forr(i, 1, n)
        {
            if (r)
            {
                edges.pb({root, ne[i] + 1});
            }
            else
            {
                edges.pb({ne[i - 1] + 1, ne[i] + 1});
            }
            if (vec[ne[i]])
                r = true;
            else
                r = false;
        }
        for (auto p : edges)
            cout << p.f << " " << p.s << "\n";
    }
}