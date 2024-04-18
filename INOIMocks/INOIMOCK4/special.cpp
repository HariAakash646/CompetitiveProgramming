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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        int n;
        char l;
        cin >> n >> l;
        string str1, str2;
        cin >> str1;
        cin >> str2;
        bool out = false;

        frange(i, 27)
        {
            for (auto e : str1)
            {
                if (e == l)
                {
                    cout << str1 << "\n";
                    out = true;
                    break;
                }
            }
            if (out || str1 == str2)
                break;
            for (int i = n - 1; i >= 0; i--)
            {
                if (str1[i] == 'z')
                {
                    str1[i] = 'a';
                }
                else
                {
                    str1[i]++;
                    break;
                }
            }
        }
        if (!out)
            cout << "NO\n";
    }
}