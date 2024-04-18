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
    int t;
    cin >> t;
    frange(_, t)
    {
        int n, m;
        cin >> n >> m;
        string str;
        cin >> str;
        deque<int> dq;
        frange(i, m) dq.pb(0);
        int curr = 0;
        int c = 0;
        frange(i, n)
        {
            frang(j, m)
            {
                int x = dq.pop_back();
                x <<= 1;
                if (__builtin_popcount(x))
                    c--;
                if (str[i] == '1')
                    x |= 1;
                if (__builtin_popcount(x))
                    c++;
                dq.push_front(x);
            }
        }
    }
}