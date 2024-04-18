#include <bits/stdc++.h>
#include <iostream>

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

int n, m, sz;
int cnt = 0;
vs str, vec;

bool rec(vi &res, int len, int id)
{
    vi dupres = res;
    if (id >= n)
    {
        string out = str[0];
        forr(i, 1, n)
        {
            frange(j, res[i])
            {
                out += "_";
            }
            out += str[i];
        }
        if (out.size() < 3 || out.size() > 16 || binary_search(all(vec), out))
        {
            // cnt++;
            return false;
        }
        else
        {
            cout << out << "\n";
            return true;
        }
    }
    int v = 1;
    while (sz + v + len - 1 <= 16)
    {
        res[id] = v;
        bool out = rec(res, len + v - 1, id + 1);
        if (out)
            return true;
        if (cnt >= m)
            return false;
        res = dupres;
        v++;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    str = vs(n);
    vec = vs(m);
    sz = 0;
    frange(i, n)
    {
        cin >> str[i];
        sz += str[i].size();
    }
    frange(i, m) cin >> vec[i];
    sort(all(str));
    sort(all(vec));
    do
    {
        vi res(n + 1, 1);
        bool out = rec(res, n - 1, 1);
        if (out)
            return 0;
        if (cnt >= m)
        {
            printf("-1");
            return 0;
        }
    } while (next_permutation(all(str)));
    printf("-1");
}