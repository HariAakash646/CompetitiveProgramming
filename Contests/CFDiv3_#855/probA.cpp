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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        char pre = '0';
        bool fail = false;
        for (char e : str)
        {
            if (e == 'm' || e == 'M')
            {
                if (pre == '0' || pre == 'm' || pre == 'M')
                    ;
                else
                {
                    printf("NO\n");
                    fail = true;
                    break;
                }
            }
            else if (e == 'e' || e == 'E')
            {
                if (pre == 'm' || pre == 'M' || pre == 'e' || pre == 'E')
                    ;
                else
                {
                    printf("NO\n");
                    fail = true;
                    break;
                }
            }
            else if (e == 'o' || e == 'O')
            {
                if (pre == 'e' || pre == 'E' || pre == 'o' || pre == 'O')
                    ;
                else
                {
                    printf("NO\n");
                    fail = true;
                    break;
                }
            }
            else if (e == 'w' || e == 'W')
            {
                if (pre == 'o' || pre == 'O' || pre == 'w' || pre == 'W')
                    ;
                else
                {
                    printf("NO\n");
                    fail = true;
                    break;
                }
            }
            else
            {
                printf("NO\n");
                fail = true;
                break;
            }
            pre = e;
        }

        if (!fail)
        {
            if (str[n - 1] != 'w' && str[n - 1] != 'W')
            {
                printf("NO\n");
                fail = true;
            }
            else
                printf("YES\n");
        }
    }
}