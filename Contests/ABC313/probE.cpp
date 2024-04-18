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

lli mod = 998244353;

int main()
{
    int n;
    string num;
    cin >> n >> num;
    lli c = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (num[i] == '1')
        {
            c += 1 + c * (num[i + 1] - '1');
        }
        else
        {
            if (num[i + 1] != '1')
            {
                printf("-1");
                return 0;
            }
            else
            {
                c += 1;
            }
        }
        c %= mod;
    }
    printf("%lld", c - 1);
}