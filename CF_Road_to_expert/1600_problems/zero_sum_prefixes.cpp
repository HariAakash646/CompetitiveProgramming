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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        lli tot = 0;
        int c = 0;
        int cn = 0;
        lli v;
        int zer = -1;
        map<lli, int> cnt;
        frange(i, n)
        {
            scd(vec[i]);
            int a = vec[i];
            if (a == 0)
            {
                zer = i;
                vec[i] = -tot;
                tot = 0;
                c++;
                v = vec[i];
                cn = 1;
                cnt = {};
                cnt[v] = 1;
            }
            else
            {
                tot += a;
                if (zer != -1)
                {
                    cnt[-tot]++;
                    if (cnt[-tot] > cnt[v])
                    {
                        c += cnt[-tot] - cnt[v] - 1;
                        v = -tot;
                        tot = 0;
                        vec[i] = v;
                        cn = cnt[v];
                    }
                }
                if (tot == 0)
                    c++;
            }
        }
        printf("%d\n", c);
    }
}