#include <bits/stdc++.h>
#include <iostream>

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
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi prefh(n + 2);
    vi prefp(n + 2);
    vi prefs(n + 2);
    frange(i, n)
    {
        char c;
        cin >> c;
        prefh[i + 1] = prefh[i];
        prefp[i + 1] = prefp[i];
        prefs[i + 1] = prefs[i];
        if (c == 'H')
        {
            prefh[i + 1]++;
        }
        else if (c == 'P')
        {
            prefp[i + 1]++;
        }
        else if (c == 'S')
        {
            prefs[i + 1]++;
        }
    }
    int ma = 0;
    forr(i, 1, n + 1)
    {
        ma = max(ma, max({prefh[i] + prefp[n] - prefp[i], prefh[i] + prefs[n] - prefs[i], prefp[i] + prefh[n] - prefh[i], prefp[i] + prefs[n] - prefs[i], prefs[i] + prefh[n] - prefh[i], prefs[i] + prefp[n] - prefp[i]}));
    }
    cout << ma;
}