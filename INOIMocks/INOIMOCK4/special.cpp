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
        // string done = "";
        // bool doneb = false;
        int pos;
        // frange(i, n - 1)
        // {
        //     if (str1[i] != str2[i])
        //     {
        //         out = true;
        //         pos = i;
        //         break;
        //     }
        //     if (str1[i] == l || str2[i] == l)
        //     {
        //         out = true;
        //         doneb = true;
        //         done = (str1[i] == l) ? str1 : str2;
        //         break;
        //     }
        // }
        // if (out && doneb)
        // {
        //     cout << done << "\n";
        // }
        // else if (out)
        // {
        //     forr(i, pos + 1, n)
        //     {
        //         if (l >= str1[i])
        //         {
        //             string st(1, l);
        //             str1.replace(i, 1, st);
        //             cout << str1 << "\n";
        //             break;
        //         }
        //         else if (l <= str2[i])
        //         {
        //             string st(1, l);
        //             str2.replace(i, 1, st);
        //             cout << str2 << "\n";
        //             break;
        //         }
        //     }
        // }
        // else
        // {
        //     if (l >= str1[n - 1] && l <= str2[n - 1])
        //     {
        //         str2.erase(n - 1);
        //         cout << str2 << l << "\n";
        //     }
        //     else
        //     {
        //         cout << "NO\n";
        //     }
        // }
        for (auto e : str1)
        {
            if (e == l)
            {
                out = true;
            }
        }
        if (out)
        {
            cout << str1 << "\n";
            return 0;
        }
        char e = str1[n - 1];
        char e1;
        str1.erase(n - 1);
        frange(i, 26)
        {
            e1 = e + i;
            if (e1 > 'z')
            {
                e1 = 'a';
                char tmp = str1[n - 2];
                str1.erase(n - 2);
                str1 += tmp + 1;
            }
            if (e1 == l)
            {
                if (str1 + e1 <= str2)
                {
                    out = true;
                    break;
                }
            }
        }
        if (out)
        {
            cout << str1 + e1 << "\n";
        }
        else
            cout << "NO\n";
    }
}