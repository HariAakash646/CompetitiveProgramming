#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;
    vi rang(n);
    int fg = -1, fh = -1, lg = -1, lh = -1;
    frange(i, n)
    {
        if (str[i] == 'G')
        {
            if (fg == -1)
                fg = i;
            lg = i;
        }
        if (str[i] == 'H')
        {
            if (fh == -1)
                fh = i;
            lh = i;
        }
    }
    frange(i, n)
    {
        int a;
        cin >> a;
        rang[i] = a - 1;
    }
    int leadg = -1, leadh = -1;
    if (rang[fg] >= lg)
    {
        leadg = fg;
    }
    if (rang[fh] >= lh)
    {
        leadh = fh;
    }
    lli c = 0;
    if (leadh != -1 && leadg != -1)
    {
        c = 1;
    }
    frange(i, leadg)
    {
        if (str[i] == 'H')
        {
            if (rang[i] >= leadg)
            {
                c++;
            }
        }
    }
    frange(i, leadh)
    {
        if (str[i] == 'G')
        {
            if (rang[i] >= leadh)
            {
                c++;
            }
        }
    }
    printf("%lld", c);
}