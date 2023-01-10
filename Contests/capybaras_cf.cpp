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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int t;
    cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    frange(i, t)
    {
        string str;
        cin >> str;
        bool done = false;
        forr(l, 1, str.size() - 1, 1)
        {
            forr(r, l + 1, str.size(), 1)
            {
                string a = str.substr(0, l);
                string b = str.substr(l, r - l);
                string c = str.substr(r, str.size() - r);
                if (a <= b && b <= c)
                {
                    cout << a << " " << b << " " << c << "\n";
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }
        if (!done)
            cout << ":(";
    }
    return 0;
}