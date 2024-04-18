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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        string str1, str2;
        cin >> str1;
        cin >> str2;
        int n1 = str1.size();
        int n2 = str2.size();
        if (str1[0] == str2[0])
        {
            cout << "YES\n";
            cout << str1[0] << "*"
                 << "\n";
            continue;
        }
        if (str1[n1 - 1] == str2[n2 - 1])
        {
            cout << "YES\n";
            cout << "*" << str1[n1 - 1] << "\n";
            continue;
        }
        if (n1 >= 2 && n2 >= 2)
        {
            bool over = false;
            frange(i, n1 - 1)
            {
                bool done = false;
                frange(j, n2 - 1)
                {
                    if (str1[i] == str2[j] && str1[i + 1] == str2[j + 1])
                    {
                        cout << "YES\n";
                        cout << "*" << str1[i] << str1[i + 1] << "*\n";
                        done = true;
                        break;
                    }
                }
                if (done)
                {
                    over = true;
                    break;
                }
            }
            if (over)
                continue;
        }
        cout << "NO\n";
    }
}