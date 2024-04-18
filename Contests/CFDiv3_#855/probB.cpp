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
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        vii vec(27);
        for (auto e : str)
        {
            if (e >= 'a' && e <= 'z')
            {
                vec[e - 'a'].f++;
            }
            else
            {
                vec[e - 'A'].s++;
            }
        }
        int tot = 0;
        frange(i, 26)
        {
            int a = min(vec[i].f, vec[i].s);
            int b = max(vec[i].f, vec[i].s);
            tot += a;
            int d = (b - a) / 2;
            tot += min(k, d);
            k -= min(k, d);
        }
        cout << tot << "\n";
    }
}