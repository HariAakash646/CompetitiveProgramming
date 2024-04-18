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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vvi plank;
int n, k;

bool check(int x)
{
    bool done = false;

    forr(i, 1, k + 1)
    {
        int c = 0;
        bool skip = false;
        int curr = true;
        for (auto e : plank[i])
        {
            if (e - c - 1 > x)
            {
                if (skip || (e - c - 1) / 2 > x)
                {
                    curr = false;
                    break;
                }
                else
                {
                    skip = true;
                }
            }
            c = e;
        }
        if (n - c > x)
        {
            // cout << x << n << c << "\n";
            if (skip || (n - c) / 2 > x)
            {
                curr = false;
            }
            else
            {
                skip = true;
            }
        }
        if (curr)
            done = true;
    }
    return done;
}

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {

        cin >> n >> k;
        plank = vvi(k + 1);
        forr(i, 1, n + 1)
        {
            int v;
            cin >> v;
            plank[v].pb(i);
        }
        int lo = 0;
        int hi = n;
        while (lo != hi)
        {
            int mid = (lo + hi) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo << "\n";
    }
}