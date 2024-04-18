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
    t = 50;
    frange(_, t)
    {
        int n;
        char l;
        n = rand() % 10000;
        l = (rand() % 26) + 'a';
        string str1, str2;
        frange(i, n)
        {
            str1 += (rand() % 26) + 'a';
            str2 += (rand() % 26) + 'a';
        }
        bool out = false;
        string done = "";
        bool doneb = false;
        int pos;
        frange(i, n - 1)
        {
            if (str1[i] != str2[i])
            {
                out = true;
                pos = i;
                break;
            }
            if (str1[i] == l || str2[i] == l)
            {
                out = true;
                doneb = true;
                done = (str1[i] == l) ? str1 : str2;
                break;
            }
        }
        string outstr = "";
        bool pas = true;
        if (out && doneb)
        {
            cout << done << "\n";
            outstr = done;
        }
        else if (out)
        {
            forr(i, pos + 1, n)
            {
                if (l >= str1[i])
                {
                    string st(1, l);
                    str1.replace(i, 1, st);
                    cout << str1 << "\n";
                    outstr = str1;
                    break;
                }
                else if (l <= str2[i])
                {
                    string st(1, l);
                    str2.replace(i, 1, st);
                    cout << str2 << "\n";
                    outstr = str2;
                    break;
                }
            }
        }
        else
        {
            if (l >= str1[n - 1] && l <= str2[n - 1])
            {
                str2.erase(n - 1);
                cout << str2 << l << "\n";
                outstr = str2 + l;
            }
            else
            {
                cout << "NO\n";
                pas = false;
            }
        }
        if (pas)
        {
            if (!(str1 <= outstr && outstr <= str2))
            {
                cout << str1 << " " << outstr << " " << str2 << "\n";
            }
        }
    }
}