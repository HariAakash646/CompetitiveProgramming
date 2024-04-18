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

vector<pair<lli, lli>> vec;
int n;
lli xl1, yl1, xl2, yl2;

bool check(lli d)
{
    lli k = d / n;
    lli r = d % n;
    lli x = xl1 + vec[n].f * k;
    x += vec[r].f;
    lli y = yl1 + vec[n].s * k;
    y += vec[r].s;
    if (abs(x - xl2) + abs(y - yl2) <= d)
        return true;
    else
        return false;
}

int main()
{
    cin >> xl1 >> yl1 >> xl2 >> yl2;

    cin >> n;
    string str;
    cin >> str;
    vec = vector<pair<lli, lli>>(n + 1);
    frange(i, n)
    {
        vec[i + 1] = vec[i];
        if (str[i] == 'U')
        {
            vec[i + 1].s++;
        }
        else if (str[i] == 'D')
        {
            vec[i + 1].s--;
        }
        else if (str[i] == 'L')
        {
            vec[i + 1].f--;
        }
        else if (str[i] == 'R')
        {
            vec[i + 1].f++;
        }
    }
    lli h = 1e14 + 10;
    lli l = 0;
    while (l < h)
    {
        lli mid = (l + h) / 2;
        if (check(mid))
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (l <= 1e14)
        cout << l;
    else
        cout << -1;
}