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
    lli x = 0;
    lli y = 0;
    lli n = 3;
    while (x == y)
    {
        cout << "? " << n << " " << 1 << endl;
        cin >> x;
        if (x == 0)
            return 0;
        if (x == -1)
        {
            cout << "! " << n - 1 << endl;
            return 0;
        }
        cout << "? " << 1 << " " << n << endl;
        cin >> y;
        if (y == 0)
            return 0;
        n++;
    }
    cout << "! " << x + y << "\n";
}