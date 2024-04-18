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
typedef pair<int, pii> piii;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int st = -1;
    frange(i, n)
    {
        bool done = false;
        frange(j, m)
        {
            if (s1[i + j] != '?' && s1[i + j] != s2[j])
            {
                done = true;
                break;
            }
        }
        if (!done)
        {
            st = i;
        }
    }
    if (st == -1)
    {
        cout << "UNRESTORABLE";
    }
    else
    {
        frange(i, st)
        {
            if (s1[i] == '?')
            {
                cout << 'a';
            }
            else
            {
                cout << s1[i];
            }
        }
        frange(i, m)
        {
            cout << s2[i];
        }
        forr(i, st + m, n)
        {
            if (s1[i] == '?')
            {
                cout << 'a';
            }
            else
            {
                cout << s1[i];
            }
        }
    }
}