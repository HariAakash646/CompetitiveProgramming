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
#define MP make_pair
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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int q;
    cin >> q;
    frange(i, q)
    {
        int m;
        char c;
        cin >> m >> c;
        int curr = 0;
        int ma = 0;
        int p1 = 0;
        int p2 = 0;
        if (str[p1] != c)
            curr++;
        while (p2 < n)
        {
            ma = max(ma, p2 - p1 + 1);
            if (curr <= m)
            {
                p2++;
                if (str[p2] != c)
                    curr++;
            }
            while (curr > m)
            {
                if (str[p1] != c)
                    curr--;
                p1++;
            }
        }
        printf("%d\n", ma);
    }
}