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

vi find_subset(int l, int u, vi w)
{
    int n = w.size();

    vii w2(n);
    frange(i, n)
    {
        w2[i] = {w[i], i};
    }
    sort(all(w2));
    vi out = {};
    int id = 0;
    lli v = 0;
    while (id < n && v <= u)
    {
        v += w2[id].f;
        out.pb(w2[id].s);
        id++;
    }
    // cout << v << "\n";
    if (v < l)
    {
        out = {};
        // cout << "a\n";
        return out;
    }
    else
    {
        if (v <= u)
        {
            // cout << "b\n";
            return out;
        }
        id--;
        v -= w2[id].f;

        out.pop_back();
        int k = 0;
        for (int i = n - 1; i >= id; i--)
        {
            if (v >= l)
                break;
            if (k >= out.size())
                break;
            v += w2[i].f - w2[k].f;
            out[k] = w2[i].s;
            k++;
        }
        if (v >= l && v <= u)
        {
            return out;
        }
        else
        {
            // cout << "c\n";
            out = {};
            return out;
        }
    }
}

// int main()
// {
//     int n, a, b;
//     cin >> n >> a >> b;
//     vi vec(n);
//     frange(i, n) cin >> vec[i];
//     vi out = find_subset(a, b, vec);

//     for (auto e : out)
//         cout << e << " ";
// }