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
    int n, m;
    cin >> n >> m;

    int mi = 0;
    int ma = 0;
    frange(i, n)
    {
        int sing = m / 2;
        int dou = m / 4;
        int mic = 0;
        int mac = 0;
        string flr;
        cin >> flr;
        int c11 = 0;
        int c10 = 0;
        int j;
        for (j = 0; j < m-1; j++)
        {
            if (flr[j] == '1' && flr[j + 1] == '1')
            {
                c11++;
                j++;
            }
            else if (flr[j] == '1')
            {
                c10++;
                j++;
            }
        }
        // printf("%d %d\n", c11, c10);
        if (j == m - 1 && flr[j] == '1')
        {
            sing--;
            mac++;
            mic++;
        }
        int sc11 = c11;
        int sc10 = c10;
        if (sing <= 2 * c11)
        {
            c11 -= (sing+1) / 2;
            mac += sing;
        }
        else
        {
            mac += 2 * c11;
            sing -= 2 * c11;
            c11 = 0;
        }
        mac += c10;
        mac += c11;
        ma += mac;
        sing = m / 2;
        if (dou <= sc11)
        {
            sc11 -= dou;
            mic += dou;
        }
        else
        {
            mic += sc11;
            dou -= sc11;
            sc11 = 0;
        }
        mic += 2 * sc11;
        mic += sc10;
        mi += mic;
    }
    printf("%d %d", mi, ma);
}