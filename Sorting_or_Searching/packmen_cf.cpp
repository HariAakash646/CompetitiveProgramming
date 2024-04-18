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

int n;
vi ast;
vi pack;
vb vis;

bool check(int x)
{
    int k = ast.size();
    vis = vb(k);
    int id = 0;
    for (auto e : pack)
    {
        int v = 0;
        int v1 = e;
        int st = id;
        while (id < k && ast[id] - ast[st] + min(abs(e - ast[st]), abs(e - ast[id])) <= x)
        {

            id++;
            // while (id < k && ast[id] > v1 && ast[id] < e)
            // {
            //     id++;
            // }
        }

        if (id >= k)
            return true;
    }
    return false;
}

int main()
{
    cin >> n;
    string str;
    cin >> str;
    frange(i, n)
    {
        if (str[i] == '*')
            ast.pb(i);
        if (str[i] == 'P')
            pack.pb(i);
    }
    int lo = 0;
    int hi = 2e5;

    while (lo != hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    printf("%d", lo);
}