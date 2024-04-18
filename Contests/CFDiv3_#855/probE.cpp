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
    int t;
    cin >> t;
    frange(_, t)
    {
        int n, k;
        cin >> n >> k;
        string s1, s2;
        cin >> s1 >> s2;
        vi v1(26);
        vi v2(26);
        for (auto e : s1)
        {
            v1[e - 'a']++;
        }
        for (auto e : s2)
        {
            v2[e - 'a']++;
        }
        bool done = false;
        frange(i, 26)
        {
            if (v1[i] != v2[i])
            {
                cout << "NO\n";
                done = true;
                break;
            }
        }
        if (done)
            continue;
        if (n >= 2 * k)
        {
            cout << "YES\n";
            continue;
        }

        if (n <= 3)
        {
            if (s1 == s2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (n == 4)
        {
            if (s1[1] == s2[1] && s1[2] == s2[2])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (n == 5)
        {
            if (s1[2] == s2[2])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}