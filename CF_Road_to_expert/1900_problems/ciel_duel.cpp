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
    int n, m;
    cin >> n >> m;
    vi atk;
    vi def;
    vii jiro;
    frange(i, n)
    {
        string typ;
        cin >> typ;
        int x;
        cin >> x;
        if (typ == "ATK")
        {
            atk.pb(x);
            jiro.pb({x, 1});
        }
        else
        {
            def.pb(x);
            jiro.pb({x, 0});
        }
    }
    vi ciel(m);
    mseti ciset;
    frange(i, m)
    {
        cin >> ciel[i];
        ciset.insert(ciel[i]);
    }
    sort(all(atk));
    sort(all(def));
    sort(all(ciel), greater<int>());
    sort(all(jiro), greater<>());
    int tot = 0;
    frange(i, min(m, int(atk.size())))
    {
        if (atk[i] < ciel[i])
        {
            tot += ciel[i] - atk[i];
        }
        else
        {
            break;
        }
    }
    if (m >= n)
    {
        int val = 0;
        frange(i, n)
        {
            if (jiro[i].s)
            {
                auto it = prev(ciset.end());
                if (*it >= jiro[i].f)
                {
                    val += *it - jiro[i].f;
                    ciset.erase(it);
                }
                else
                {
                    val = 0;
                    ciset = {};
                    break;
                }
            }
            else
            {
                auto it = ciset.upper_bound(jiro[i].f);

                if (it == ciset.end())
                {
                    val = 0;
                    ciset = {};
                    break;
                }
                else
                {
                    ciset.erase(it);
                }
            }
        }
        for (auto e : ciset)
        {
            val += e;
        }
        tot = max(tot, val);
    }

    printf("%d", tot);
}