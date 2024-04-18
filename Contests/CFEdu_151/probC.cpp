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
typedef long double ld;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int t;
    cin >> t;
    frange(_, t)
    {
        string str;
        cin >> str;
        int n = str.size();
        int m;
        cin >> m;
        string l, r;
        cin >> l >> r;
        string out = "";
        bool over = false;
        int curr = -1;
        frange(i, m)
        {

            int v = -1;
            bool done = false;
            int ma = curr;
            forr(j, l[i] - '0', r[i] - '0' + 1)
            {

                int id = -1;
                forr(k, curr + 1, n)
                {
                    int v = str[k] - '0';
                    if (v == j)
                    {
                        id = k;
                        break;
                    }
                }
                if (id == -1)
                {
                    out += char(j + '0');
                    done = true;
                    break;
                }
                else
                {
                    if (id >= ma)
                    {
                        ma = id;
                        v = j;
                    }
                }
            }
            if (done)
            {
                forr(k, i + 1, m)
                {
                    out += l[k];
                }
                over = true;
                break;
            }
            else
            {
                curr = ma;
                out += char(v + '0');
            }
        }
        if (!over)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            // cout << out << "\n";
        }
    }
}