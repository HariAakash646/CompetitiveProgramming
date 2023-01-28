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
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    frange(i, n)
    {
        string str;
        cin >> str;
        if (str.size() < 3)
        {
            printf("-1\n");
            continue;
        }
        int rep = str.size() - 1;
        int oidx = -1;
        forr(i, 1, str.size() - 1)
        {
            int d = 0;
            if (str[i] == 'O')
            {
                oidx = i;
                if (str[i - 1] == 'M')
                    d++;
                if (str[i + 1] == 'O')
                    d++;
                rep = min(rep, int(str.size() - 1 - d));
            }
        }
        if (oidx != -1)
            printf("%d\n", rep);
        else
        {
            printf("-1\n");
        }
    }
}